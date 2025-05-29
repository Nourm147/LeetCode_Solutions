class Solution
{
public:
    int myAtoi(std::string s)
    {
        long long result = 0;
        int i = 0;
        bool isNegative = false, findZero = true;
        while (s[i] == ' ' && i < s.length())
        {
            i++;
        }
        if (i >= s.length() || (!isDigit(s[i]) && s[i] != '+' && s[i] != '-'))
        {
            return 0;
        }
        if (s[i] == '-')
        {
            isNegative = true;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        while (i < s.length())
        {
            if (isDigit(s[i]))
            {
                while (s[i] == '0' && findZero)
                {
                    i++;
                }
                if (i >= s.length() || !isDigit(s[i]))
                {
                    break;
                }
                findZero = false;
                result *= 10;
                if (result > pow(2, 31) - 1)
                    break;
                result += (s[i] - '0');
                i++;
            }
            else
            {
                break;
            }
        }
        if (isNegative)
            result *= -1;

        if (result > pow(2, 31) - 1)
            return pow(2, 31) - 1;

        else if (result < pow(-2, 31))
            return pow(-2, 31);

        return result;
    }
    bool isDigit(char a)
    {
        return (a >= '0' && a <= '9');
    }
};
