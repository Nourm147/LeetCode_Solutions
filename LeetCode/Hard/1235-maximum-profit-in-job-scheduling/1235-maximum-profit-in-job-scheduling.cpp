class Solution {
public:

    int getMax(vector<int>& dp, vector<pair<int, pair<int, int>>>& v, int ind){
        if(ind >= v.size())
            return 0;

        if(~dp[ind])
            return dp[ind];
        
        int it = lower_bound(v.begin(), v.end(), make_pair(v[ind].second.first, make_pair(0, 0))) - v.begin();
        int ch1 = v[ind].second.second + getMax(dp, v, it);
        int ch2 = getMax(dp, v, ind + 1);
        return dp[ind] = max(ch1, ch2);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> dp(startTime.size(), -1);
        vector<pair<int, pair<int, int>>> v(startTime.size());
        for(int i = 0; i < startTime.size(); i++){
            v[i].first = startTime[i];
            v[i].second.first = endTime[i];
            v[i].second.second = profit[i];
        }

        sort(v.begin(), v.end());

        return getMax(dp, v, 0);
    }
};