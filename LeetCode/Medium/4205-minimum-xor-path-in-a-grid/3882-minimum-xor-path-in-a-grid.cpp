class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int getMin(vector<vector<int>>& grid, int i, int j, int res){
        if(i >= m || j >= n)
            return INT_MAX;
        if(i == m - 1 && j == n - 1)
        {
           return (grid[i][j] ^ res);
        }

        int& ret = dp[i][j][res];
        if(~ret)
            return ret;

        int ch1 = getMin(grid, i + 1, j, res ^ grid[i][j]);
        int ch2 = getMin(grid, i, j + 1, res ^ grid[i][j]);

        return ret = min(ch1, ch2);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(1025, -1)));
        return getMin(grid, 0, 0, 0);
    }
};