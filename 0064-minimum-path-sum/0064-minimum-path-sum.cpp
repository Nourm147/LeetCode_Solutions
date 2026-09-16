class Solution {
public:

    long long dp[205][205];

    long long path(int m, int n, int i, int j, vector<vector<int>>& grid){
        if(i >= m || j >= n || i < 0 || j < 0)
            return INT_MAX;
        if(i == m - 1 && j == n - 1)
            return grid[i][j];

        if(~dp[i][j])
            return dp[i][j];
        
        long long ch1 = path(m, n, i + 1, j, grid) + grid[i][j];
        long long ch2 = path(m, n, i, j + 1, grid) + grid[i][j];

        return dp[i][j] = min(ch1, ch2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return path(grid.size(), grid[0].size(), 0, 0, grid);
    }
};