class Solution {
public:

    int minCost(vector<int>& cuts, vector<vector<int>>& dp, int i, int j)
    {
        if(j - i <= 1)
            return 0;

        if(~dp[i][j])
            return dp[i][j];

        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++)
        {
            ans = min(ans, minCost(cuts, dp, i, k) + minCost(cuts, dp, k, j) + cuts[j] - cuts[i]);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int cn = cuts.size();
        vector<vector<int>> dp(cn + 1, vector<int>(cn + 1, -1));
        return minCost(cuts, dp, 0, cn - 1);
    }
};