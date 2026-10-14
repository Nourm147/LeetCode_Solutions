class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tr(128, 0);
        for(int i = 0; i < t.size(); i ++)
        {
            tr[t[i]]++;
        }

        vector<int> current(128, 0);
        int mnS;
        int mnL = INT_MAX;

        int l = 0, r = 0;
        while(r < s.size())
        {
            current[s[r]]++;
            bool valid = true;
            for(int i = 0; i < 128; i ++)
            {
                if(tr[i] > current[i])
                {
                    valid = false;
                    break;
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
                    for(int i = 0; i < 128; i ++)
                    {
                        if(tr[i] > current[i])
                        {
                            valid = false;
                            break;
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