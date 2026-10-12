class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        searchCorrectPath("", results, 0, 0, n);
        return results;
    }
    void searchCorrectPath(std::string result, std::vector<std::string> &tracker, int open, int close, int max)
    {
        if (open < max)
        {
            searchCorrectPath(result + "(", tracker, open + 1, close, max);
        }
        if (close < max && close < open)
        {
            searchCorrectPath(result + ")", tracker, open, close + 1, max);
        }
        if (result.length() >= 2 * max)
        {
            tracker.push_back(result);
        }
    }
};
