class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        for(int i = 1; i <= amount; i++){
            int ans = INT_MAX / 2;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0)
                    ans = min(ans, dp[i - coins[j]] + 1);
            }
            dp[i] = ans;
        }
        if(dp[amount] == INT_MAX / 2)
            return -1;
        return dp[amount];
    }
};