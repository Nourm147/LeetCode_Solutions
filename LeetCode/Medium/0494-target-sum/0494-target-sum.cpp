class Solution {
public:

    map<int, int> dp[21];

    int solve(int ind, int rem, vector<int>& nums){
        if(ind >= nums.size())
        {
            if(rem == 0)
                return 1;
            return 0;
        }

        if(dp[ind].find(rem) != dp[ind].end())
            return dp[ind][rem];

        int ch1 = solve(ind + 1, rem - nums[ind], nums);
        int ch2 = solve(ind + 1, rem + nums[ind], nums);

        return dp[ind][rem] = ch1 + ch2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};