class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mn = INT_MAX;
        for(int len = l; len <= r; len++){
            int sum = 0;
            for(int i = 0; i < len; i++){
                sum += nums[i];
            }
            if(sum > 0)
                mn = min(mn, sum);
            for(int i = len; i < nums.size(); i++){
                sum += nums[i] - nums[i - len];
                if(sum > 0)
                    mn = min(mn, sum);
            }
        }
        return (mn == INT_MAX ? -1 : mn);
    }
};