#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int count = 0;

public:
    // string getPer(string &s, int n, vector<bool> &exist, int k)
    // {
    //     if (s.size() == n)
    //     {
    //         count++;
    //         if (count == k)
    //             return s;
    //         return "";
    //     }

    //     string s1;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (exist[i])
    //             continue;

    //         s.push_back('0' + i);
    //         exist[i] = true;
    //         s1 = getPer(s, n, exist, k);
    //         exist[i] = false;
    //         s.pop_back();
    //         if (s1 != "")
    //             break;
    //     }
    //     return s1;
    // }

    string getPermutation(int n, int k)
    {
        // vector<bool> exist(n + 1, false);
        // string s = "";
        // return getPer(s, n, exist, k);
        int fact = 1;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
            fact *= i;
        }
        string result = "";
        k--;

        while (!v.empty())
        {
            if (n == 0)
                fact = 1;
            else
                fact /= n;
            n--;
            int mod = k / fact;
            result.push_back('0' + v[mod]);
            v.erase(v.begin() + mod);
            k %= fact;
        }
        return result;
    }
};

