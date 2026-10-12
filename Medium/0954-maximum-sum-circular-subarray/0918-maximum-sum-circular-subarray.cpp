class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sumx = 0, sumn = 0, tot = 0;;
        int n = nums.size();
        int mx = INT_MIN;
        int mn = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(sumx < 0)
                sumx = 0;
            sumx += nums[i];
            mx = max(sumx, mx);

            if(sumn > 0)
                sumn = 0;
            sumn += nums[i];
            mn = min(sumn, mn);
            
            tot += nums[i];
        }

        if(tot == mn)
            return mx;

        return max(mx, tot - mn);
    }
};