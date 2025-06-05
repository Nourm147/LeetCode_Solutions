class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::string result = "";
        std::map<int, char> RomanMap = {
            {1, 'I'},
            {10, 'X'},
            {100, 'C'},
            {1000, 'M'},
            {5, 'V'},
            {50, 'L'},
            {500, 'D'}};

        int t = 1000;
        while (num != 0)
        {
            int temp = num / t;
            if (t == 1000 && temp != 0)
            {
                for (int i = 0; i < temp; i++)
                {
                    result.push_back(RomanMap[t]);
                }
            }
            else if (temp != 0)
            {
                if (temp == 4)
                {
                    result.push_back(RomanMap[t]);
                    result.push_back(RomanMap[getPreviousPhase(t)]);
                }
                else if (temp == 9)
                {
                    result.push_back(RomanMap[t]);
                    result.push_back(RomanMap[getPreviousPhase(getPreviousPhase(t))]);
                }
                else
                {
                    if (temp >= 5)
                    {
                        result.push_back(RomanMap[getPreviousPhase(t)]);
                        temp -= 5;
                    }
                    for (int i = 0; i < temp; i++)
                    {
                        result.push_back(RomanMap[t]);
                    }
                }
            }
            num %= t;
            t /= 10;
        }
        return result;
    }
    int getPreviousPhase(int a)
    {
        if (a == 100 || a == 10 || a == 1)
        {
            return a * 5;
        }
        else
        {
            return a * 2;
        }
    }
};

