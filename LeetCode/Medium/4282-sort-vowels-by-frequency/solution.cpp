class Solution {
public:

    bool vawel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        vector<pair<int, char>> fr;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i ++){
            if(vawel(s[i]))
            {
                if(mp.find(s[i]) == mp.end())
                {
                    fr.push_back({0, s[i]});
                    mp[s[i]] = fr.size() - 1;
                }
                fr[mp[s[i]]].first ++;
            }
        }

        stable_sort(fr.begin(), fr.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; 
        });

        int j = 0;
        for(int i = 0; i < s.size(); i ++){
            if(vawel(s[i]))
            {
                if(fr[j].first == 0)
                {
                    j ++;
                }
                s[i] = fr[j].second;
                fr[j].first --;
            }
        }
        return s;

    }
};
