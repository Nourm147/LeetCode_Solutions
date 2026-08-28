class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> box[3][3], row[9], col[9];

        for(int i = 0; i < 9; i ++)
        {
            for(int j = 0; j < 9; j ++){
                char element = board[i][j];

                if(element == '.')
                    continue;

                if(box[i / 3][j / 3].find(element) != box[i / 3][j / 3].end())
                    return false;
                if(row[i].find(element) != row[i].end())
                    return false;
                if(col[j].find(element) != col[j].end())
                    return false;

                box[i / 3][j / 3].insert(element);
                row[i].insert(element);
                col[j].insert(element);
            }
        }

        return true;
    }
};