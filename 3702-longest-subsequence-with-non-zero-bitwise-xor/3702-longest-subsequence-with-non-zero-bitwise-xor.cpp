class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum = 0;
        int mx = 0;
        set<int> s;
        for(int i = 0; i < nums.size(); i ++){
            s.insert(nums[i]);
            sum ^= nums[i];
        }
        if(sum != 0)
            return nums.size();

        if(s.find(0) == s.end() || s.size() > 1)
            return nums.size() - 1;

        return 0;
    }
};