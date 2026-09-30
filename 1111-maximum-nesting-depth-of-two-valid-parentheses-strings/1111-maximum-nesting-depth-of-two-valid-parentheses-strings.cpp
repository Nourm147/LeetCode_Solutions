class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        int n = seq.size();
        vector<int> result(n, 0);

        for(int i = 0; i < n; i ++)
        {
            if(seq[i] == '('){
                depth ++;
                result[i] = depth % 2;
            }
            else{
                result[i] = depth % 2;
                depth --;
            }
        }
        return result;
    }
};