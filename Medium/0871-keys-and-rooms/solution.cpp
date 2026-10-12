#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<bool> visited;

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        visited.resize(rooms.size(), false);
        dfs(rooms, 0);
        for (bool v : visited)
        {
            if (!v)
            {
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>> &rooms, int room)
    {
        visited[room] = true;
        for (int key : rooms[room])
        {
            if (!visited[key])
            {
                dfs(rooms, key);
            }
        }
    }
};
