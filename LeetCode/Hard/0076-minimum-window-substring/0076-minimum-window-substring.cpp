class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tr;
        for(int i = 0; i < t.size(); i ++)
        {
            tr[t[i]]++;
        }

        map<char, int> current;
        int mnS;
        int mnL = INT_MAX;

        int l = 0, r = 0;
        while(r < s.size())
        {
            current[s[r]]++;
            bool valid = true;
            for(auto& p : tr)
            {
                if(p.second > current[p.first])
                {
                    valid = false;
                }
            }
            if(valid)
            {
                if(r - l + 1 < mnL){
                    mnS = l;
                    mnL = r - l + 1;
                }
                while(valid){
                    current[s[l]]--;
                    l++;
                    for(auto& p : tr)
                    {
                        if(p.second > current[p.first])
                        {
                            valid = false;
                        }
                    }
                    if(valid)
                    {
                        if(r - l + 1 < mnL){
                            mnS = l;
                            mnL = r - l + 1;
                        }
                    }
                }
            }
            r++;
        }
        if(mnL != INT_MAX)
            return s.substr(mnS, mnL);
        return "";
    }
};