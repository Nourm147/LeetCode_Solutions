class Solution {
public:
    int maxProduct(int n) {
        vector<int> v {0, 0};
        while(n != 0){
            int i = 1;
            if(v[1] > v[0])
                i = 0;
            if(v[i] < n % 10){
                v[i] = n % 10;
            }
            n /= 10;
        }

        return v[0] * v[1];
    }
};