class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 0;
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1])
                count ++;
            else
            {
                mx = max(mx, count + 1);
                count = 0;
            }
        }
        mx = max(mx, count + 1);
        count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1])
                count ++;
            else
            {
                mx = max(mx, count + 1);
                count = 0;
            }
        }
        mx = max(mx, count + 1);

        return mx;
    }
};