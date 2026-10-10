class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        int n = nums1.size();
        map<int, int, greater<int>> mp;

        for(int i = 0; i < n; i++)
        {
            mp[abs(nums1[i] - nums2[i])] ++;
        }

        vector<pair<int, int>> v;
        long long k = k1 + k2;

        for(auto p : mp)
        {
            v.push_back({p.first, p.second});
        }
        v.push_back({0, 0});

        for(int i = 1; i < v.size(); i++)
        {
            int preNum = v[i - 1].second;
            int pre = v[i - 1].first;

            int cur = v[i].first;
            long long dec = 1LL * (pre - cur) * preNum;

            if(k >= dec)
            {
                v[i - 1].second = 0;
                v[i].second += preNum;
                k -= dec;
            }
            else
            {
                int preDec = k / v[i - 1].second;
                v[i - 1].first -= preDec;
                int rem = k % v[i - 1].second;
                v[i - 1].second -= rem;
                v.push_back({v[i - 1].first - 1, rem});
                k = 0;
                break;
            }
        }

        long long sum = 0;

        for(int i = 0; i < v.size(); i++)
        {
            sum += 1LL * v[i].first * v[i].first * v[i].second;
        }
        
        return sum;
    }
};