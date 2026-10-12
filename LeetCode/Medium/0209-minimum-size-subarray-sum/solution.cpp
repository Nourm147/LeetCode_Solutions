class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum = 0;
        int l = 0, n = nums.size();
        int opt = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= target){
                opt = min(opt, i - l + 1);
                sum -= nums[l];
                l ++;
            }
        }
        return (opt == INT_MAX) ? 0 : opt;
    }
};
