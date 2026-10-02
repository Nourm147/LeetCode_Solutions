class Solution {
public:

    void generate(int n, vector<string>& result, string& s, int ind, int open)
    {
        if(ind == n * 2){
            if(open == 0)
                result.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            generate(n, result, s, ind + 1, open + 1);
            s.pop_back();
        }

        if(open > 0)
        {
            s.push_back(')');
            generate(n, result, s, ind + 1, open - 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generate(n, result, s, 0, 0);
        return result;
    }
};