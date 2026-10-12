class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        for(int i = n - 1; i >= n - k; i --){
            if(mul > 0)
                total += (long long) mul * nums[i];
            else
                total += nums[i];
            mul --;
        }
        return total;
    }
};
