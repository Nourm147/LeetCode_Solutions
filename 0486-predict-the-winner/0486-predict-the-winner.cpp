class Solution {
public:

    
    int dp[21][21];

    int go(vector<int> &v, int i, int j)
    {
        if(i == j)
            return v[i];

        if(~dp[i][j])
            return dp[i][j];

        return dp[i][j] = max(v[i] - go(v, i + 1, j), v[j] - go(v, i, j - 1));
    }


    bool predictTheWinner(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return go(nums, 0, nums.size() - 1) >= 0;
    }
};