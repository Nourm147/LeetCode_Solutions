class Solution {
public:
    int smallestNumber(int n, int t) {

        int q = n / 10;
        int r = n % 10;

        int rmin = t / gcd(max(q, 1), t);

        int nxt = ((r + rmin - 1) / rmin) * rmin;

        int x = nxt - (nxt - 10) * (nxt / 10);
                
        return 10 * q + x;
    }
};