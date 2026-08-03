class Solution {
public:


    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MAX);

        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int ch1 = stoneValue[i] - dp[i + 1];

            int ch2 = INT_MIN;
            if (i + 1 < n) {
                ch2 = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];
            }

            int ch3 = INT_MIN;
            if (i + 2 < n) {
                ch3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3];
            }

            dp[i] = max({ch1, ch2, ch3});
        }

        int ans = dp[0];

        if(ans == 0)
            return "Tie";
        else if(ans > 0)
            return "Alice";
        else 
            return "Bob";
    }
};