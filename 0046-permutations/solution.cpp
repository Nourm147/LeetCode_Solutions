#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> result;
    int n;
    map<int, bool> m;

public:
    void buildPermutation(vector<int> &v)
    {
        if (v.size() == n)
        {
            result.push_back(v);
            return;
        }
        for (auto &i : m)
        {
            if (i.second)
                continue;
            v.push_back(i.first);
            i.second = true;
            buildPermutation(v);
            v.pop_back();
            i.second = false;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {

        n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            m.insert({nums[i], false});
        }
        vector<int> v;
        buildPermutation(v);

        return result;
    }
};
