class Solution {
public:
    int n, m;

    long long dp[105][105];

    long long go(vector<vector<int>>& v, int i, int j){
        if(i >= m || j >= n || v[i][j] == 1)
            return 0;
        if(i == m - 1 && j == n - 1)
            return 1;

        if(~dp[i][j])
            return dp[i][j];

        return dp[i][j] = go(v, i + 1, j) + go(v, i, j + 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));

        return go(obstacleGrid, 0, 0);
    }
};