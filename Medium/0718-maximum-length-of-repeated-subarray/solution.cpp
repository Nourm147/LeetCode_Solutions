#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    const int base = 131;
    const int mod = 1e9 + 7;

public:
    bool check(vector<int> &nums1, vector<int> &nums2, int len)
    {
        long long hash = 0;
        long long power = 1;
        for (int i = 0; i < len; i++)
        {
            hash = (hash * base + nums1[i]) % mod;
            power = (power * base) % mod;
        }
        set<long long> seen = {hash};
        for (int i = len; i < nums1.size(); i++)
        {
            hash = ((hash * base % mod - (nums1[i - len] * power) % mod + mod) % mod + nums1[i]) % mod;
            seen.insert(hash);
        }

        hash = 0;
        for (int i = 0; i < len; i++)
        {
            hash = (hash * base + nums2[i]) % mod;
        }
        if (seen.find(hash) != seen.end())
        {
            return true;
        }
        for (int i = len; i < nums2.size(); i++)
        {
            hash = ((hash * base % mod - (nums2[i - len] * power) % mod + mod) % mod + nums2[i]) % mod;
            if (seen.find(hash) != seen.end())
            {
                return true;
            }
        }
        return false;
    }

    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int left = 0, right = min(nums1.size(), nums2.size()), ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(nums1, nums2, mid))
            {
                left = mid + 1;
                ans = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
