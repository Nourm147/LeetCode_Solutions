class Solution {
public:
    long long maxValue(vector<int>& nums) {
        long long sum = 0;
        long long mx = INT_MIN;

        long long ans = 0;
        long long neg = 1;
        for(int i = 0; i < nums.size(); i ++){
            ans += neg * nums[i];
            neg *= -1;
        }

        for(int i = 0; i < nums.size() - 1; i += 2)
        {
            sum = max(sum, 0LL) + nums[i + 1] - nums[i];
            mx = max(sum, mx);
        }

        sum = 0;
        for(int i = 1; i < nums.size() - 1; i += 2)
        {
            sum = max(sum, 0LL) - nums[i + 1] + nums[i];
            mx = max(sum, mx);
        }

        return max(ans + 2 * mx, ans);
    }
};

// a, b, c, d, e, f