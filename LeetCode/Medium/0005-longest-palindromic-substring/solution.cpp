class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        if (s.empty())
        {
            return "";
        }
        std::string maxString = "";
        maxString.push_back(s[0]);
        float center = 0.5;
        while (center < s.length() - 1)
        {
            float it = (center == int(center)) ? 0 : 0.5;
            while (int(center - it) > 0 || int(center + it) < s.length())
            {
                bool temp = s[int(center - it)] == s[int(center + it)];
                if (temp)
                {
                    it++;
                }
                if (int(center - it) < 0 || int(center + it) >= s.length())
                {
                    it--;
                    break;
                }
                if (!temp)
                {
                    it--;
                    break;
                }
            }
            if (maxString.length() < int(2 * it + 1))
            {
                maxString.clear();
                for (int i = int(center - it), n = int(center + it + 1); i < n; i++)
                {
                    maxString.push_back(s[i]);
                }
            }
            center += 0.5;
        }
        return maxString;
    };
};
