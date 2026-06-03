#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int j = indexDifference;
        int mx = 0, mn = 0;
        for (int i = indexDifference; i < nums.size(); i++)
        {
            j = i - indexDifference;

            if (nums[j] < nums[mn])
                mn = j;
            if (nums[j] > nums[mx])
                mx = j;

            if (nums[i] - nums[mn] >= valueDifference)
                return {mn, i};

            if (nums[mx] - nums[i] >= valueDifference)
                return {i, mx};
        }
        return {-1, -1};
    }
};
