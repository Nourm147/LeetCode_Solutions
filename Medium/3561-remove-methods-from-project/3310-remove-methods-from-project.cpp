class Solution {
public:

    void dfs(int i, vector<vector<int>>& adj, vector<bool>& v)
    {
        if(v[i])
            return;
        v[i] = true;
        for(int j = 0; j < adj[i].size(); j ++){
            dfs(adj[i][j], adj, v);
        }
    }
    bool dfs(int i, vector<vector<int>>& adj, vector<bool>& v, vector<bool>& visited)
    {
        if(v[i])
            return false;
        if(visited[i])
            return true;
        visited[i] = true;
        bool valid = true;
        for(int j = 0; j < adj[i].size(); j ++){
            valid = valid && dfs(adj[i][j], adj, v, visited);
        }
        return valid;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> v(n, false);
        vector<vector<int>> adj(n);
        for(int i = 0; i < invocations.size(); i ++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(k, adj, v);

        bool valid = true;
        vector<bool> visit(n, false);
        for(int i = 0; i < n; i ++){
            if(!v[i])
                valid = valid && dfs(i, adj, v, visit);
        }
        vector<int> result;
        if(valid)
        {

            for(int i = 0; i < n; i ++){
                if(!v[i])
                    result.push_back(i);
            }
        }
        else{
            for(int i = 0; i < n; i ++){
                result.push_back(i);
            }
        }

        return result;
    }
};