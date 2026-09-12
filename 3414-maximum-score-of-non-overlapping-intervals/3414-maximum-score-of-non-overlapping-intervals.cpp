class Solution {
public:
    long long dp[50005][5];
    bool dpBuild[50005][5];
    vector<int> memo[50005][5];

    long long compute(int ind, int size, vector<vector<int>>& v, vector<int>& st, int n)
    {
        if(size > 4)
            return INT_MIN;
        if(ind >= n){
            if(size <= 4)
                return 0;
            else
                return INT_MIN;
        }

        if(~dp[ind][size])
            return dp[ind][size];

        int next = upper_bound(st.begin(), st.end(), v[ind][1]) - st.begin();
        long long ch1 = compute(next, size + 1, v, st, n) + v[ind][2];

        long long ch2 = compute(ind + 1, size, v, st, n);

        return dp[ind][size] = max(ch1, ch2);
    }


    vector<int> build(int ind, int size, vector<vector<int>>& v, vector<int>& st, int n)
    {
        if(ind >= n || size > 4){
            return {};
        }
        
        if(dpBuild[ind][size])
            return memo[ind][size];

        long long ret = compute(ind, size, v, st, n);

        int next = upper_bound(st.begin(), st.end(), v[ind][1]) - st.begin();
        long long ch1 = compute(next, size + 1, v, st, n) + v[ind][2];

        long long ch2 = compute(ind + 1, size, v, st, n);

        bool found = false;
        vector<int> best;

        if(ret == ch1)
        {
            vector<int> path = build(next, size + 1, v, st, n);
            path.push_back(v[ind][3]);
            sort(path.begin(), path.end());

            best = path;
            found = true;
        }

        if(ret == ch2)
        {
            vector<int> path = build(ind + 1, size, v, st, n);
            if (!found || path < best) {
                best = path;
            }
        }

        dpBuild[ind][size] = true;
        return memo[ind][size] = best;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        memset(dp, -1, sizeof(dp));
        memset(dpBuild, 0, sizeof(dpBuild));

        int n = intervals.size();
        vector<int> starts (n);

        for(int i = 0; i < n; i ++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i ++){
            starts[i] = intervals[i][0];
        }

        long long maxW = compute(0, 0, intervals, starts, n);

        vector<int> result = build(0, 0, intervals, starts, n);

        sort(result.begin(), result.end());

        return result;
    }
};