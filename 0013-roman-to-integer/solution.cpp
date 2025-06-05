class Solution
{
public:
    int romanToInt(std::string s)
    {
        int result = 0;
        std::map<char, int> RomanMap = {
            {'I', 1},
            {'X', 10},
            {'C', 100},
            {'M', 1000},
            {'V', 5},
            {'L', 50},
            {'D', 500}};
        int lastAdd = 10000;
        for (int i = 0, n = s.length(); i < n; i++)
        {
            if (lastAdd < RomanMap[s[i]])
            {
                result += RomanMap[s[i]] - 2 * lastAdd;
                continue;
            }
            result += RomanMap[s[i]];
            lastAdd = RomanMap[s[i]];
        }
        return result;
    }
};
