class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1 || s.empty())
        {
            return s;
        }

        std::string resultString = "";
        int RowExcute = numRows * 2 - 2, iDown = RowExcute, iUp = 0, iMem = 0;
        for (int i = 0; i < numRows; i++)
        {
            iMem = i;
            if (iDown == RowExcute || iUp == RowExcute)
            {
                while (iMem < s.length())
                {
                    resultString.push_back(s[iMem]);
                    iMem += RowExcute;
                }
            }
            else
            {
                bool up = false;
                while (iMem < s.length())
                {
                    if (up)
                    {
                        resultString.push_back(s[iMem]);
                        iMem += iUp;
                    }
                    else
                    {
                        resultString.push_back(s[iMem]);
                        iMem += iDown;
                    }
                    up = !up;
                }
            }
            iDown -= 2, iUp += 2;
        }
        return resultString;
    }
};
