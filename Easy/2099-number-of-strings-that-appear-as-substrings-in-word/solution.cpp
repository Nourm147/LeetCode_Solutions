class Solution {
public:

    vector<int> getKMP(string &s){
        vector<int> res(s.size());
        res[0] = 0;
        int j = 0;
        for(int i = 1; i < s.size(); i ++){
            while(j > 0 && s[i] != s[j]){
                j = res[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            res[i] = j;
        }
        return res;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int results = 0;
        for(int i = 0; i < patterns.size(); i++){
            string &s = patterns[i];
            vector<int> pat = getKMP(s);
            int k = 0;
            for(int j = 0; j < word.size(); j++){
            while(k > 0 && word[j] != s[k]){
                k = pat[k - 1];
            }
            if(word[j] == s[k]){
                k++;
            }
            if(k == s.size()){
                results++;
                break;
            }
        }
            
        }
        return results;
    }
};
