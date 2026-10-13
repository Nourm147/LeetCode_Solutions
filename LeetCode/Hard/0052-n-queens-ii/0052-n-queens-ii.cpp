class Solution {
public:

    vector<int> col, up, down;
    int solve(int n, int ind)
    {
        if(ind > n)
            return 0;
        if(ind == n)
        {
            return 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i ++)
        {
            if(col[i] == 0 && up[n + i - ind] == 0 && down[i + ind] == 0)
            {
                col[i] = 1;
                up[n + i - ind] = 1;
                down[i + ind] = 1;
                ans += solve(n, ind + 1);
                col[i] = 0;
                up[n + i - ind] = 0;
                down[i + ind] = 0;
            }
        }
        return ans;
    }

    int totalNQueens(int n) {
        col.resize(n, 0);
        up.resize(2 * n, 0);
        down.resize(2 * n, 0);
        return solve(n, 0);
    }
};