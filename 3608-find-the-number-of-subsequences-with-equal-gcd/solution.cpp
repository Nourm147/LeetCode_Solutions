class Solution {
public:
    int n;
    vector<int> v;
    int MOD = 1000000007;

    int dp[205][205][205];

    int go(int ind, int gcd1, int gcd2)
    {
        if(ind == n){
            return gcd1 == gcd2;
        }
        if(~dp[ind][gcd1][gcd2])
            return dp[ind][gcd1][gcd2];

        int ch1 = go(ind + 1, __gcd(gcd1, v[ind]), gcd2);
        int ch2 = go(ind + 1, gcd1, __gcd(gcd2, v[ind]));
        int ch3 = go(ind + 1, gcd1, gcd2);

        return dp[ind][gcd1][gcd2] = ((ch1 + ch2) % MOD + ch3) % MOD;
    }


    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        v = nums;

        memset(dp, -1, sizeof(dp));

        long long ans = go(0, 0, 0);

        return ans - 1;
    }
};
