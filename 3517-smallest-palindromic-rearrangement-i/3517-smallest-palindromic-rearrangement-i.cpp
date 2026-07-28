class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> fr(28, 0);
        int odd = -1;
        for(int i = 0; i < s.size(); i ++)
        {
            fr[s[i] - 'a'] ++;
        }

        int i = 0, j = s.size() - 1; 
        for(int ind = 0; ind < fr.size(); ind ++)
        {
            while(fr[ind] > 1){
                s[i] = ('a' + ind);
                s[j] = ('a' + ind);
                fr[ind] -= 2;
                i ++;
                j--;
            }
        }

        return s;
    }
};