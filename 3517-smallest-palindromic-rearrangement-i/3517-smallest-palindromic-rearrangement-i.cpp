class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> fr(28, 0);
        int odd = -1;
        for(int i = 0; i < s.size(); i ++)
        {
            fr[s[i] - 'a'] ++;
        }
        string res;
        for(int i = 0; i < fr.size(); i ++)
        {
            if(fr[i] % 2)
                odd = i;
            for(int j = 0; j < fr[i] / 2; j ++){
                res += ('a' + i);
            }
        }
        if(odd != -1)
            res += ('a' + odd);

        for(int i = fr.size() - 1; i >= 0; i --)
        {
            for(int j = 0; j < fr[i] / 2; j ++){
                res += ('a' + i);
            }
        }

        return res;
    }
};