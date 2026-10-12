class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    int mxtime;
    vector<int> fee;
    int n;

    long long dp[1005][1005];

    long long go(int i, int time){
        if(i >= n || time > mxtime)
            return INT_MAX;

        if(i == n - 1)
        {
            if(time <= mxtime)
                return fee[i];
            else
                return INT_MAX;
        }

        if(~dp[i][time])
            return dp[i][time];

        long long ans = INT_MAX;
        for(int j = 0; j < adj[i].size(); j ++){
            ans = min(ans, go(adj[i][j].first, adj[i][j].second + time) + fee[i]);
        }

        return dp[i][time] = ans;
    }


    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        mxtime = maxTime;
        fee = passingFees;
        n = passingFees.size();

        memset(dp, -1, sizeof(dp));

        adj.resize(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        long long ans = go(0, 0);
        return (ans == INT_MAX ? -1 : ans);
    }
};
