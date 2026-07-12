class Solution {
public:

    int dp[40005][4];

    int dfs(int i, vector<int> &v, int dir){
        if(i >= v.size())
            return 0;
        if(v[i - 1] - v[i] == 0)
            return 0;
        if((v[i - 1] - v[i]) / abs(v[i - 1] - v[i]) != dir)
            return 0;

        if(~dp[i][dir + 1])
            return dp[i][dir + 1];
        
        return dp[i][dir + 1] = dfs(i + 1, v, dir * -1) + 1;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1)
            return 1;

        memset(dp, -1, sizeof(dp));
        int pre = 1;

        int len = 0;

        while(pre < arr.size()){
            if(arr[pre - 1] - arr[pre] == 0){
                pre ++;
                continue;
            }
            int l = dfs(pre, arr, (arr[pre - 1] - arr[pre])/abs(arr[pre - 1] - arr[pre])) + 1;
            pre = l + pre - 1;
            len = max(l, len);
        }
        
        return max(len, 1);
    }
};
