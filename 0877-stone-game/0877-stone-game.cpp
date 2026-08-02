class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int dp[piles.size() + 1][piles.size() + 1];

        memset(dp, -1, sizeof(dp));

        auto go = [&] (auto &&self ,int i, int j){
            if(i == j)
                return piles[i];
            if(~dp[i][j])
                return dp[i][j];
            
            return dp[i][j] = max(piles[i] - self(self, i + 1, j), piles[j] - self(self, i, j - 1));
        };

        return go(go, 0, piles.size()- 1) > 0;
    }
};