class Solution {
public:

    int dp[60];
    int getMax(int rem){
        if(rem < 0)
            return 0;
        if(rem == 0)
            return 1;

        if(~dp[rem])
            return dp[rem];

        int ans = 0;
        for(int i = 1; i <= rem; i++)
        {
            ans = max(ans, i * getMax(rem - i));            
        }
        
        return dp[rem] = ans;
    }


    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;

        memset(dp, -1, sizeof(dp));
        return getMax(n);
    }
};