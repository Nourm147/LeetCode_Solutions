class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x)
        {
            if (abs(result * 10.0) > __INT32_MAX__)
                return 0;
            result *= 10;
            result += x % 10;
            x /= 10;
        }

        return result;
    }
};
