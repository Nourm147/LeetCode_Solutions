class Solution {
public:

    int dp[10005];
    int solve(int rem)
    {
        if(rem == 0)
            return 0;

        if(~dp[rem])
            return dp[rem];

        int ans = rem;
        for(int i = 1; i * i <= rem; i++)
            ans = min(ans, 1 + solve(rem - i * i));

        return dp[rem] = ans;
    }


    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);        
    }
};