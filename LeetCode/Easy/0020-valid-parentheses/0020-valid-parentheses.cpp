class Solution {
public:

    bool correctPair(char open, char close)
    {
        if(open == '(' && close == ')')
            return true;
        if(open == '[' && close == ']')
            return true;
        if(open == '{' && close == '}')
            return true;

        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty() || !correctPair(st.top(), s[i]))
                    return false;
                st.pop();
            }
        }
        
        if(!st.empty())
            return false;

        return true;
    }
};