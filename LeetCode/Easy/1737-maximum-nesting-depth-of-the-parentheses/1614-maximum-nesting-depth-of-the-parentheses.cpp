class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int mxCount = 0;
        for(char c : s)
        {
            if(c == '(')
                count ++;
            if(c == ')')
                count --;
            
            mxCount = max(mxCount, count);
        }

        return mxCount;
    }
};