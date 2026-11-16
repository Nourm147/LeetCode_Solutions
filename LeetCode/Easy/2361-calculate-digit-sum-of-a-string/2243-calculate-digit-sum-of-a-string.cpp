class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string r;
            for(int j = 0; j < s.size(); j += k){
                int sum = 0;
                for(int i = j; i < min(j + k, (int)s.size()); i++){
                    sum += s[i] - '0';
                }
                r += to_string(sum);
            }
            s = r;
        }

        return s;
    }
};