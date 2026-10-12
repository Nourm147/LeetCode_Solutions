class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> v;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '1')
                v.push_back(i);
        }

        if(v.size() < k){
            return "";
        }

        int r = k - 1;

        int end = k - 1;
        int mn = v[r] - v[r - k + 1];
        for(; r < v.size(); r++){
            if(v[r] - v[r - k + 1] <= mn){
                end = r;
                mn = v[r] - v[r - k + 1];
            }
        }

        vector<string> results;
        for(r = k - 1; r < v.size(); r++){
            if(v[r] - v[r - k + 1] == mn){
                results.push_back(s.substr(v[r - k + 1], mn + 1));
            }
        }

        sort(results.begin(), results.end());

        return results[0];
    }
};