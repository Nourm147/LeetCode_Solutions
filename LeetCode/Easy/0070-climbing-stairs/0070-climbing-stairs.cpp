class Solution {
public:


    int climbStairs(int n) {

        int dp1 = 1, dp2 = 0;
        for(int i = n - 1; i >=0; i--){
            int dp3 = dp1 + dp2;
            dp2 = dp1;
            dp1 = dp3;
        }

        return dp1;
    }
};