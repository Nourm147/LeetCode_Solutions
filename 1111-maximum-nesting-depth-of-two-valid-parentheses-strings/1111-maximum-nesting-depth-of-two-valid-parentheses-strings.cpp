class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int open = 0;
        int depth = 0;
        int n = seq.size();
        for(int i = 0; i < n; i ++)
        {
            if(seq[i] == '('){
                open ++;
            }
            else{
                open --;
            }
            depth = max(depth, open);
        }

        open = 0;
        int target = depth / 2;
        vector<int> result(n, 0);

        for(int i = 0; i < n; i ++)
        {
            if(seq[i] == '('){
                if(open >= target)
                    result[i] = 1;
                open ++;
            }
            else{
                open --;
                if(open >= target)
                    result[i] = 1;
            }
        }
        return result;
    }
};