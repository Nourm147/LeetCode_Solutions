class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int l = 0;
        int mxSize = 0;
        for(int i = 0; i < nums.size(); i ++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] <= 0)
                    mp.erase(nums[l]);
                l++;
            }
            if(mp[nums[i]] <= k)
                mxSize = max(mxSize, i - l + 1);
        }

        return mxSize;
    }
};