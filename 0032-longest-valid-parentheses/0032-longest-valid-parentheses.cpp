class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> v(s.size(), false);
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(!st.empty())
                {
                    v[i] = true;
                    v[st.top()] = true;
                    st.pop();
                }
            }
        }
        int mx = 0;
        int cur = 0;
        for(int i = 1; i < v.size(); i ++)
        {
            if(v[i] == v[i - 1] && v[i] == true)
                cur ++;
            else
            {
                mx = max(mx, (cur != 0) ? cur + 1 : 0);
                cur = 0;
            }
        }
        mx = max(mx, (cur != 0) ? cur + 1 : 0);

        return mx;
    }
};