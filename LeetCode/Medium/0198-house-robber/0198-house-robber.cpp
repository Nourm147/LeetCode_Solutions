class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;

        for(int i = n - 1; i >= 0; i--){
            dp3 = max(dp1, dp2 + nums[i]);
            dp2 = dp1;
            dp1 = dp3;
        }

        return dp1;
    }
};