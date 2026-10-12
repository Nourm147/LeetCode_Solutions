import os
import re
import json
import shutil
import requests

# AUTOMATICALLY LOCK WORKING DIRECTORY TO WHERE THIS SCRIPT LIVES
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
os.chdir(BASE_DIR)

CACHE_FILE = "leetcode_cache.json"
README_FILE = "../README.md"
GRAPHQL_URL = "https://leetcode.com/graphql"
REPO_URL = "https://github.com/Nourm147/LeetCode_Solutions/tree/main"

CODE_EXTENSIONS = {".cpp", ".cc", ".c", ".py", ".java", ".js", ".ts", ".go", ".rs", ".php", ".rb"}
MIN_FILE_SIZE = 30

def load_cache():
    if os.path.exists(CACHE_FILE):
        with open(CACHE_FILE, "r", encoding="utf-8") as f:
            return json.load(f)
    return {}

def save_cache(cache):
    with open(CACHE_FILE, "w", encoding="utf-8") as f:
        json.dump(cache, f, indent=4)

def has_valid_solution(folder_path):
    if not os.path.exists(folder_path):
        return False
    for root, _, files in os.walk(folder_path):
        for file in files:
            if os.path.splitext(file)[1].lower() in CODE_EXTENSIONS:
                if os.path.getsize(os.path.join(root, file)) >= MIN_FILE_SIZE:
                    return True
    return False

def fetch_problem_metadata(title_slug):
    clean_slug = title_slug.lower().replace("_", "-").strip()
    query = """
    query questionData($titleSlug: String!) {
        question(titleSlug: $titleSlug) {
            questionId
            title
            difficulty
            topicTags {
                name
            }
        }
    }
    """
    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com/",
        "User-Agent": "Mozilla/5.0"
    }
    try:
        response = requests.post(
            GRAPHQL_URL,
            json={"query": query, "variables": {"titleSlug": clean_slug}},
            headers=headers,
            timeout=10
        )
        if response.status_code == 200:
            data = response.json()
            if "data" in data and data["data"] and data["data"]["question"]:
                q = data["data"]["question"]
                return {
                    "questionId": str(q["questionId"]).zfill(4),
                    "difficulty": q["difficulty"],
                    "topics": [tag["name"] for tag in q["topicTags"]]
                }
    except Exception as e:
        print(f"API Error for {clean_slug}: {e}")
    return None

def main():
    pattern = re.compile(r"^\d+-(.+)$")
    cache = load_cache()
    updated_cache = False

    for diff in ["Easy", "Medium", "Hard"]:
        os.makedirs(diff, exist_ok=True)

    problems = {}
    ignore_dirs = {".git", ".github", "venv", "__pycache__", "Easy", "Medium", "Hard"}

    search_roots = [".", "Easy", "Medium", "Hard"]
    found_folders = []
    for sr in search_roots:
        if os.path.exists(sr):
            for item in os.listdir(sr):
                item_path = os.path.join(sr, item)
                if os.path.isdir(item_path) and item not in ignore_dirs:
                    found_folders.append((item_path, item))

    for full_path, d in found_folders:
        match = pattern.match(d)
        if match:
            slug = match.group(1)

            if not has_valid_solution(full_path):
                print(f"[*] Skipping folder without code: {d}")
                continue

            if slug not in cache:
                print(f"Fetching official metadata for slug: '{slug}'...")
                meta = fetch_problem_metadata(slug)
                if meta:
                    cache[slug] = meta
                    updated_cache = True
                else:
                    print(f"[!] Warning: Could not fetch metadata for {slug}. Keeping folder as-is.")
                    continue
            
            meta = cache[slug]
            q_id = meta["questionId"]
            diff = meta["difficulty"]
            canonical_name = f"{q_id}-{slug}"
            target_dir = os.path.join(diff, canonical_name)

            if os.path.abspath(full_path) != os.path.abspath(target_dir):
                if os.path.exists(target_dir):
                    print(f"[!] Overwriting existing conflicting folder '{canonical_name}'")
                    shutil.rmtree(target_dir)
                
                os.makedirs(diff, exist_ok=True)
                shutil.move(full_path, target_dir)
                print(f"-> Renamed/Moved '{d}' to '{diff}/{canonical_name}'")

            problems[canonical_name] = {
                "id": q_id,
                "slug": slug,
                "difficulty": diff,
                "topics": meta["topics"],
                "path": f"{diff}/{canonical_name}"
            }

    if updated_cache:
        save_cache(cache)

    stats = {"Easy": 0, "Medium": 0, "Hard": 0}
    topics_map = {}

    for full_name, info in problems.items():
        diff = info["difficulty"]
        stats[diff] = stats.get(diff, 0) + 1
        for topic in info["topics"]:
            if topic not in topics_map:
                topics_map[topic] = []
            topics_map[topic].append({
                "name": full_name,
                "difficulty": diff,
                "path": f"{REPO_URL}/{info['path']}/"
            })

    print(f"\nSynced Count -> Total: {len(problems)} | Easy: {stats['Easy']} | Medium: {stats['Medium']} | Hard: {stats['Hard']}")

    if os.path.exists(README_FILE):
        with open(README_FILE, "r", encoding="utf-8") as f:
            readme_text = f.read()
    else:
        readme_text = "# LeetCode_Solutions\nCollection of LeetCode questions to ace the coding interview!\n\n<!---LeetCode Topics Start-->\n<!---LeetCode Topics End-->"

    new_content_lines = []
    new_content_lines.append("# LeetCode Topics\n")
    new_content_lines.append("## Statistics")
    new_content_lines.append(f"- **Total Problems:** {len(problems)}")
    new_content_lines.append(f"- **Easy:** {stats.get('Easy', 0)}")
    new_content_lines.append(f"- **Medium:** {stats.get('Medium', 0)}")
    new_content_lines.append(f"- **Hard:** {stats.get('Hard', 0)}\n")
    new_content_lines.append("---")

    for topic in sorted(topics_map.keys()):
        new_content_lines.append(f"\n## {topic}")
        new_content_lines.append("| Problem Name | Difficulty |")
        new_content_lines.append("| ------- | ------- |")
        sorted_probs = sorted(topics_map[topic], key=lambda x: x["name"])
        for p in sorted_probs:
            new_content_lines.append(f"| [{p['name']}]({p['path']}) | {p['difficulty']} |")

    generated_block = "\n".join(new_content_lines)

    start_marker = "<!---LeetCode Topics Start-->"
    end_marker = "<!---LeetCode Topics End-->"

    if start_marker in readme_text and end_marker in readme_text:
        parts = readme_text.split(start_marker)
        after_end = readme_text.split(end_marker)[1]
        final_readme = parts[0] + start_marker + "\n" + generated_block + "\n" + end_marker + after_end
    else:
        base_header = readme_text.split("## LeetCode Topics")[0] if "## LeetCode Topics" in readme_text else readme_text
        final_readme = base_header.strip() + f"\n\n{start_marker}\n{generated_block}\n{end_marker}\n"

    with open(README_FILE, "w", encoding="utf-8") as f:
        f.write(final_readme)

    print("README.md successfully updated right here in the directory!")

if __name__ == "__main__":
    main()