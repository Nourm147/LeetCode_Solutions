class Solution {
public:
    int maxDistinct(string s) {
        vector<int> fr(26, 0);
        for(int i = 0; i < s.size(); i ++){
            fr[s[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i ++){
            if(fr[i] != 0)
                count ++;
        }

        return count;
    }
};