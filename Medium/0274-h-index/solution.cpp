#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        vector<int> rep(1001, 0);
        for (int i = 0; i < citations.size(); i++)
        {
            rep[citations[i]]++;
        }
        int sum = 0;
        for (int i = 1000; i >= 0; i--)
        {
            sum += rep[i];
            if (sum >= i)
            {
                return i;
            }
        }
        return 0;
    }
};
