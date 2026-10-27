class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m, string(n, '#'));
        for(int i = 0; i < n; i++){
            result[0][i] = '.';
        }
        for(int i = 0; i < m; i++){
            result[i][n - 1] = '.';
        }
        return result;
    }
};