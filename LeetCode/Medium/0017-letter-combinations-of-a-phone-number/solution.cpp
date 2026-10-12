class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        std::string letters[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> result;
        int resultSize = 1;
        for (int i = 0, n = digits.size(); i < n; i++)
        {
            resultSize *= letters[digits[i] - '2'].size();
        }
        for (int i = 0; i < resultSize; i++)
        {
            result.push_back("");
        }
        int length = resultSize;
        for (int i = 0, n = digits.size(); i < n; i++)
        {
            int size = letters[digits[i] - '2'].size(), it = -1;
            length /= size;
            for (int j = 0; j < resultSize; j++)
            {
                if (j % length == 0)
                {
                    it = (it + 1) % size;
                }
                result[j].push_back(letters[digits[i] - '2'][it]);
            }
        }

        return result;
    }
};
