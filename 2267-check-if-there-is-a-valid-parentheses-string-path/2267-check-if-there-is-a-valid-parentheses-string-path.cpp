class Solution {
public:
    int m, n;
    int dp[105][105][205];

    bool isValid(vector<vector<char>>& grid, int i, int j, int depth)
    {
        if(depth < 0 || i >=m || j >= n)
            return false;

        depth += (grid[i][j] == '(' ? 1 : -1);

        if(depth < 0)
            return false;

        if(i == m-1 && j == n-1)
        {
            return depth == 0;
        }

        int& ret = dp[i][j][depth];
        if(~ret)
            return ret;

        return ret = (isValid(grid, i + 1, j, depth)|| isValid(grid, i, j + 1, depth));

    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1 , sizeof(dp));
        return isValid(grid, 0, 0, 0);
    }
};