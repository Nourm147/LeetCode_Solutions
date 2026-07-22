class Solution {
public:

    vector<int> v;
    int n;

    double dp[105][105];

    double go(int ind, int k){
        if(ind >= n)
            return 0;

        if(k <= 0)
            return INT_MIN;

        if(dp[ind][k] != 0)
            return dp[ind][k];

        double sum = 0;
        double ans = 0;

        for(int i = ind; i < n; i ++){
            sum += v[i];
            ans = max(ans, (go(i + 1, k - 1) + sum / (double)(i - ind + 1)));
        }

        return dp[ind][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        v = nums;
        n = nums.size();

        memset(dp, 0, sizeof(dp));

        return go(0, k);
    }
};