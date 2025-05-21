class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty())
        {
            return 0;
        }

        int front = 0, back = 0, Max = 1, endIndex = s.length() - 1;
        std::map<char, bool> charMap;
        charMap.insert({s[back], true});
        while (front != endIndex)
        {
            front++;
            while (true)
            {
                if (charMap.find(s[front]) != charMap.end() && charMap[s[front]])
                {
                    charMap[s[back]] = false;
                    back++;
                }
                else if (charMap.find(s[front]) == charMap.end())
                {
                    charMap.insert({s[front], true});
                    break;
                }
                else
                {
                    charMap[s[front]] = true;
                    break;
                }
            }
            Max = std::max(Max, front - back + 1);
        }
        return Max;
    }
};
