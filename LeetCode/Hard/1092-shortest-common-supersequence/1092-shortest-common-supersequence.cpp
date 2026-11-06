class Solution {
public:

    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j)
    {
        if(i >= s1.size() || j >= s2.size())
        {
            if(j < s2.size())
                return s2.size() - j;
            if(i < s1.size())
                return s1.size() - i;
            return 0;
        }

        int& ret = dp[i][j];
        if(~ret)
            return ret;
        
        if(s1[i] == s2[j])
            return ret = solve(dp, s1, s2, i + 1, j + 1) + 1;
        
        int ch1 = solve(dp, s1, s2, i + 1, j) + 1;
        int ch2 = solve(dp, s1, s2, i, j + 1) + 1;

        return ret = min(ch1, ch2);
    }

    string build(vector<vector<int>>& dp, string& s1, string& s2, int i, int j)
    {
        if(i >= s1.size() || j >= s2.size())
        {
            if(j < s2.size())
                return s2.substr(j, s2.size() - j + 1);
            if(i < s1.size())
                return s1.substr(i, s1.size() - i + 1);
            return "";
        }
        
        if(s1[i] == s2[j])
            return string(1, s1[i]) + build(dp, s1, s2, i + 1, j + 1);
        
        int ch1 = solve(dp, s1, s2, i + 1, j) + 1;
        int ch2 = solve(dp, s1, s2, i, j + 1) + 1;

        if(ch1 >= ch2)
        {
            return string(1, s2[j]) + build(dp, s1, s2, i, j + 1);
        }else
        {
            return string(1, s1[i]) + build(dp, s1, s2, i + 1, j);
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, -1));
        solve(dp, str1, str2, 0, 0);
        return build(dp, str1, str2, 0, 0);
    }
};