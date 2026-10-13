class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            if(l != r){
                sum -= (1LL) * nums[l];
            }
            sum += (1LL) * nums[r];
            r--;
            l++;
        }
        return sum;
    }
};