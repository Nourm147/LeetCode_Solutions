class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i = min_element(nums.begin(), nums.end()) - nums.begin();
        int j = max_element(nums.begin(), nums.end()) - nums.begin();

        int mn = min(i, j);
        int mx = max(i, j);

        return min({mx + 1, (int)nums.size() - mn, mn + 1 + (int)nums.size() - mx});
    }
};