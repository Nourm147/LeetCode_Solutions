#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> inDegree;
    vector<vector<int>> adjList;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        inDegree.resize(numCourses, 0);
        adjList.resize(numCourses);
        for (auto &p : prerequisites)
        {
            adjList[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            inDegree[i] = 0;
        }
        for (auto &p : prerequisites)
        {
            inDegree[p[0]]++;
        }
        bfs(prerequisites);
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
    void bfs(vector<vector<int>> &prerequisites)
    {
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            for (auto &neighbor : adjList[course])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
    }
};
