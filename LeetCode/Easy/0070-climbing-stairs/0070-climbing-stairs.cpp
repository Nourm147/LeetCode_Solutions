class Solution {
public:


    int climbStairs(int n) {
        int dp[3] = {0, 0, 0};

        dp[n % 3] = 1;

        for(int i = n - 1; i >=0; i--){
            int ch1 = dp[(i + 1) % 3];
            int ch2 = dp[(i + 2) % 3];
            dp[i % 3] = ch1 + ch2;
        }

        return dp[0];
    }
};