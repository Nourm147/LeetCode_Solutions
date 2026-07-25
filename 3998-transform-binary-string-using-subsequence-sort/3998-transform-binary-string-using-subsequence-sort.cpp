class Solution {
public:
    int tz = 0, to = 0;

    bool check(string& s, string& t)
    {
        if(s.size() != t.size())
            return false;

        int z = tz, o = to;
        for(int i = 0; i < t.size(); i ++){
            if(t[i] == '0')
                z--;
            if(t[i] == '1')
                o --;
        }

        if(o < 0 || z < 0)
            return false;

        for(int i = 0; i < t.size(); i ++){
            if(t[i] == '?' && z > 0){
                t[i] = '0';
                z--;
            }
        }

        for(int i = 0; i < t.size(); i ++){
            if(t[i] == '?' && o > 0){
                t[i] = '1';
                o--;
            }
        }

        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < t.size(); i ++){
            if(sum1 < sum2)
                return false;
            sum1 += (s[i] == '1');
            sum2 += (t[i] == '1');
        }

        return true;
        
    }

    vector<bool> transformStr(string s, vector<string>& strs) {
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '1')
                to ++;
            else
                tz ++;
        }

        vector<bool> ans(strs.size());

        for(int i = 0; i < strs.size(); i ++){
            ans[i] = check(s, strs[i]);
        }

        return ans;
    }
};