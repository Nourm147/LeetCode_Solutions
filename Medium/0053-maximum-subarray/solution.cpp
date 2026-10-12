class Solution {
public:
    long long min(int a, long long b){
        if(a > b)
            return b;
        return a;
    }
    int maxSubArray(vector<int>& nums) {
        long long sum = 0;
        int mn = INT_MAX;
        long long ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans = max({ans, sum - mn, sum});
            mn = min(mn, sum);
        }
        return ans;
    }
};
