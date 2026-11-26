class Solution {
public:
    bool canAliceWin(int n) {
        bool result = true;
        int i = 10;
        while(n >= 0)
        {
            n -= i;
            result = !result;
            i--;
        }

        return result;
    }
};