class Solution {
public:

    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j){
        if(i >= s1.size() || j >= s2.size())
        {
            if (i == s1.size())
                return s2.size() - j;
            if(j == s2.size())
                return s1.size() - i;
            return 0;
        }
        
        int& ret = dp[i][j];
        if(~ret)
            return ret;
            
        if(s1[i] == s2[j])
            return ret = solve(dp, s1, s2, i + 1, j + 1);

        int ch1 = solve(dp, s1, s2, i + 1, j);
        int ch2 = solve(dp, s1, s2, i, j + 1);
        int ch3 = solve(dp, s1, s2, i + 1, j + 1);
    
        return ret = min({ch1, ch2, ch3}) + 1;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(dp, word1, word2, 0, 0);
    }
};