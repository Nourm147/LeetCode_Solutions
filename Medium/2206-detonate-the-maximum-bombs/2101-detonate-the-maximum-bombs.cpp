class Solution {
public:

    double dist(int x1, int y1, int x2, int y2){
        return sqrt((double)(x1 - x2) * (double)(x1 - x2) + (double)(y1 - y2) * (double)(y1 - y2));
    }

    void dfs(vector<vector<int>> &adj,vector<bool> &visited,int &count,int i)
    {
        visited[i]=true;
        count++;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
             dfs(adj,visited,count,adj[i][j]);   
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adj(bombs.size());

        for(int i = 0; i < bombs.size(); i ++){
            int x = bombs[i][0];
            int y = bombs[i][1];
            int r = bombs[i][2];

            for(int j = 0; j < bombs.size(); j ++){
                if(i != j)
                    if(r >= dist(x, y, bombs[j][0], bombs[j][1])){
                        adj[i].push_back(j);
                    }
            }
        }

        int ans = 0;
        for(int i = 0; i < bombs.size(); i ++){
            vector<bool> visited(bombs.size());
            int count = 0;
            dfs(adj, visited, count, i);
            ans = max(ans, count);
        }

        return ans;
    }
};