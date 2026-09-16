class Solution {
public:

    int dp[105][105];

    int path(int m, int n, int i, int j){
        if(i >= m || j >= n || i < 0 || j < 0)
            return 0;
        if(i == m - 1 && j == n - 1)
            return 1;

        if(~dp[i][j])
            return dp[i][j];
        
        int ch1 = path(m, n, i + 1, j);
        int ch2 = path(m, n, i, j + 1);

        return dp[i][j] = ch1 + ch2;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return path(m, n, 0, 0);
    }
};