class Solution {
public:

    bool check(vector<vector<pair<int, int>>> &ls, int mid, int n, long long k){
        vector<long long> dis(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dis[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            if(p.first > k){
                return false;
            }
            if(p.second == n - 1){
                return true;
            }
            if(p.first > dis[p.second])
                continue;

            for(auto &next : ls[p.second]){
                if(next.second < mid)
                    continue;
                if(dis[next.first] > dis[p.second] + next.second){
                    dis[next.first] = dis[p.second] + next.second;
                    pq.push({dis[next.first], next.first});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        vector<vector<pair<int, int>>> ls(online.size());
        int l = INT_MAX, r = 0;
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];

            if(!online[u] || !online[v])
                continue;
            
            l = min(l, cost);
            r = max(r, cost);
            ls[u].push_back({v, cost});
        }

        if (!check(ls, l, online.size(), k)) {
            return -1;
        }

        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(ls, mid, online.size(), k)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
