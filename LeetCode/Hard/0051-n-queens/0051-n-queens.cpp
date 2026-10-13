class Solution {
public:
    vector<vector<string>> result;

    vector<string> v;
    vector<int> col, up, down;
    void solve(int n, int ind)
    {
        if(ind > n)
            return;
        if(ind == n)
        {
            result.push_back(v);
            return;
        }
        for(int i = 0; i < n; i ++)
        {
            if(col[i] == 0 && up[n + i - ind] == 0 && down[i + ind] == 0)
            {
                col[i] = 1;
                up[n + i - ind] = 1;
                down[i + ind] = 1;
                v[ind][i] = 'Q';
                solve(n, ind + 1);
                v[ind][i] = '.';
                col[i] = 0;
                up[n + i - ind] = 0;
                down[i + ind] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, 0);
        up.resize(2 * n, 0);
        down.resize(2 * n, 0);
        v.resize(n, string(n, '.'));
        solve(n, 0);
        return result;
    }
};