class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char, int> mp;
        int l = 0;
        int mx = 0;
        for(int i = 0; i < s.size(); i ++){
            mp[s[i]]++;
            while(mp[s[i]] > 2)
            {
                mp[s[l]]--;
                l++;
            }
            mx = max(mx, i - l + 1);
        }

        return mx;
    }
};