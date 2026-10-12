class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pre(n + 1, 1), suf(n + 1, 1);

        for(int i = 1;i < n;i++){
            if(nums[i] >= nums[i-1])
                pre[i] = pre[i - 1] + 1;
        }
        
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] <= nums[i+1])
                suf[i] = suf[i+1] + 1;
        }

        int ans = max(*max_element(pre.begin(), pre.end()), *max_element(suf.begin(), suf.end()));

        if(n > 1) ans = max({ans, pre[n-2]+1, suf[1]+1});

        for(int i = 1; i < n - 1; i ++){
            if(nums[i-1] <= nums[i+1])
                ans = max(ans, pre[i - 1] + suf[i + 1] + 1);
            ans = max(ans, pre[i] + 1);
            ans = max(ans, suf[i] + 1);
        }

        return ans;
    }
};
