class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int open = 0;

        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == '(')
            {
                open ++;
                if(open == 1)
                    continue;
            }
            else
            {
                open--;
                if(open == 0)
                    continue;
            }
            result.push_back(s[i]);

        }
        return result;
    }
};