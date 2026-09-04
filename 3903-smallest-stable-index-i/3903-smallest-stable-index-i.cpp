class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n), suf(n, INT_MAX);

        for(int i = 0; i < n; i++){
            if(i == 0)
                pre[i] = nums[i];
            else
                pre[i] = max(pre[i - 1], nums[i]);
        }

        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1)
                suf[i] = nums[i];
            else
                suf[i] = min(suf[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i ++){
            if(pre[i] - suf[i] <= k){
                return i;
            }
        }

        return -1;
    }
};