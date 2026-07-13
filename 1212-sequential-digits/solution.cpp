class Solution {
public:
    int getCount(int i){
        int count = 0;
        while(i != 0){
            i /= 10;
            count ++;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        int count = getCount(low);
        int start = 0;
        vector<int> result;
        int l = 0;
        while(l < low){
            for(int i = start; i < start + count; i++){
                l = (l * 10) + i + 1;
            }
            if(l < low){
                l = 0;
            }
            start ++;
            if(start + count >= 10){
                count ++;
                start = 0;
            }
        }

        while(l <= high){
            result.push_back(l);
            l = 0;
            for(int i = start; i < start + count; i++){
                l = (l * 10) + i + 1;
            }
            start ++;
            if(start + count >= 10){
                count ++;
                start = 0;
            }
        }
        return result;
    }
    

};
