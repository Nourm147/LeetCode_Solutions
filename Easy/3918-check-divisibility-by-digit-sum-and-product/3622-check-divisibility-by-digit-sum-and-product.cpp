class Solution {
public:
    bool checkDivisibility(int n) {
        int t = n;
        int product = 1;
        int sum = 0;
        while(t != 0){
            product *= t % 10;
            sum += t % 10;
            t /= 10;
        }
        return (n % (product + sum) == 0);
    }
};