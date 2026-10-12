class Solution {
public:
    string v[3];
    int n;

    long long dp[500005][4][4];
    long long solve(int ind, int rod, int dir){
        if(ind == n)
            return 0;
        if(ind + 1 < n && v[rod][ind + 1] == '.')
            return solve(ind + 1, rod, 1);
        else if(ind + 1 >= n )
            return 0;
        
        if(~dp[ind][rod][dir])
            return dp[ind][rod][dir];
        
        long long ans = INT_MAX;
        for(int i = 0; i < 3; i++){
            if(i != rod && v[i][ind] == '.'){
                if (i < rod && dir != 0) ans = min(ans, solve(ind, i, 0) + 1);
                if (i > rod && dir != 2) ans = min(ans, solve(ind, i, 2) + 1);
            }
        }
        return dp[ind][rod][dir] = ans;
    }

    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        v[0].resize(n);
        v[1].resize(n);
        v[2].resize(n);

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            if(obstacles[i] == 0){
                v[0][i] = '.';
                v[1][i] = '.';
                v[2][i] = '.';
            }
            if(obstacles[i] == 1){
                v[0][i] = '#';
                v[1][i] = '.';
                v[2][i] = '.';
            }
            if(obstacles[i] == 2){
                v[0][i] = '.';
                v[1][i] = '#';
                v[2][i] = '.';
            }
            if(obstacles[i] == 3){
                v[0][i] = '.';
                v[1][i] = '.';
                v[2][i] = '#';
            }
        }

        return solve(0, 1, 1);
    }
};
