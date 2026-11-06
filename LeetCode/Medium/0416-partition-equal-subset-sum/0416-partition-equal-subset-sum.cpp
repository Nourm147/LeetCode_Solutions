class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<vector<int>> dp(2, vector<int>(target + 1, 0));

        dp[0][0] = dp[1][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++)
            {
                dp[i & 1][j] |= dp[(i - 1) & 1][j] | ((i < n) ? ((j - nums[i] >= 0) ? dp[(i - 1) & 1][j - nums[i]] : 0) : 0);
            }
        }

        return dp[n&1][target] == 1;
    }
};