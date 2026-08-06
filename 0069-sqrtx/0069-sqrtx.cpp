class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;
        long long start = 2, end = x, mid;
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            if(mid * mid <= x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return end;
    }
};