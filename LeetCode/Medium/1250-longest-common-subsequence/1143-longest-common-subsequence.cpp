class Solution {
public:

    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j){
        if(i >= s1.size() || j >= s2.size())
            return 0;
        if(s1[i] == s2[j])
            return solve(dp, s1, s2, i + 1, j + 1) + 1;
        
        int& ret = dp[i][j];
        if(~ret)
            return ret;

        int ch1 = solve(dp, s1, s2, i + 1, j);
        int ch2 = solve(dp, s1, s2, i, j + 1);
    
        return ret = max(ch1, ch2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return solve(dp, text1, text2, 0, 0);
    }
};