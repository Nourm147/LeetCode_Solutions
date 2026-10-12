class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int sum = 0;
        int mx = 0;
        bool nonz = false;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] != 0)
                nonz = true;
            sum ^= nums[i];
        }
        if(sum != 0)
            return nums.size();

        if(nonz)
            return nums.size() - 1;

        return 0;
    }
};