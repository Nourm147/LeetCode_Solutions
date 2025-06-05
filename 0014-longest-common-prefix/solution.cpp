class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string result = "";
        bool finished = false;
        int j = 0;
        while (!finished)
        {
            char pre = strs[0][j];
            for (int i = 0, n = strs.size(); i < n; i++)
            {
                std::string &str = strs[i];
                if (j >= str.length())
                {
                    finished = true;
                    break;
                }
                else if (str[j] == pre)
                {
                    continue;
                }
                finished = true;
                break;
            }
            if (!finished)
            {
                result.push_back(pre);
            }

            j++;
        }

        return result;
    }
};
