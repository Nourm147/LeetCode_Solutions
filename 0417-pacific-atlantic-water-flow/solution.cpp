#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int, int>> pq, aq;
        // init edges
        for (int i = 0; i < m; i++)
        {
            pac[i][0] = true;
            pq.push({i, 0});
            atl[i][n - 1] = true;
            aq.push({i, n - 1});
        }
        for (int i = 0; i < n; i++)
        {
            pac[0][i] = true;
            pq.push({0, i});
            atl[m - 1][i] = true;
            aq.push({m - 1, i});
        }
        // bfs
        bfs(heights, pq, pac);
        bfs(heights, aq, atl);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
        return ans;
    }

    // move from edges in q into the island
    void bfs(vector<vector<int>> &heights, queue<pair<int, int>> q, vector<vector<bool>> &visited)
    {
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();
            for (auto &d : dirs)
            {
                int na = a + d[0], nb = b + d[1];
                if (na < 0 || na >= heights.size() || nb < 0 || nb >= heights[0].size())
                    continue;
                if (visited[na][nb])
                    continue;
                if (heights[na][nb] < heights[a][b])
                    continue;
                visited[na][nb] = true;
                q.push({na, nb});
            }
        }
    };
};
