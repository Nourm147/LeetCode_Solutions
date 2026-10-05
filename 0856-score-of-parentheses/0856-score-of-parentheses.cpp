class Solution {
public:

    int calculate(string& s, int l, int r, vector<int>& v){
        if(l >= r)
            return 0;
        if(r - l == 1)
            return 1;

        int i = l + 1;
        while(i < r)
        {   
            if(v[i] != -1)
                break;
            i++;
        }

        int result = 0;
        while(i <= r)
        {
            int end = v[i];
            if(end == -1){
                i++;
                continue;
            }
            result += calculate(s, i, end, v);
            i = end + 1;
        }

        result *= 2;
        return result;
    }

    int scoreOfParentheses(string s) {
        stack<int> st;
        vector<int> v(s.size(), -1);

        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty())
                {
                    v[st.top()] = i;
                    st.pop();
                }
            }
        }

        int score = 0;
        int i = 0;
        while(i < s.size()){
            score += calculate(s, i, v[i], v);
            i = v[i] + 1;
        }

        return score;
    }
};