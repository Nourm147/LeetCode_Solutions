class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int tmp = n;
            int mul = 1;
            while(tmp != 0)
            {
                mul *= tmp % 10;
                tmp /= 10;
            }
            if(mul % t == 0)
                break;
            n ++;
        }

        return n;
    }
};