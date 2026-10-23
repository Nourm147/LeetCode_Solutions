class Solution {
public:


    bool checkStraightLine(vector<vector<int>>& coor) {
        sort(coor.begin(), coor.end());
        double slop = (coor[0][0] - coor[1][0]) / (double)(coor[0][1] - coor[1][1]);
        for(int i = 2; i < coor.size(); i++){
            if((coor[i - 1][0] - coor[i][0]) / (double)(coor[i - 1][1] - coor[i][1]) != slop)
                return false;
        }

        return true;
    }
};