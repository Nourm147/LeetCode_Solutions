class Solution {
public:

    vector<pair<int,int>> v;
    vector<int> bit;

    void update(int i, int val)
    {
        while(i <= v.size())
        {
            bit[i] += val;
            i += i & -i;
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }


    int reversePairs(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        bit.resize(nums.size() + 1, 0);

        for(int i = 0; i < nums.size(); i ++){
            v.push_back({nums[i], i + 1});
        }

        sort(v.begin(), v.end());
        int ans = 0;

        int s = 0, f = 0;
        
        while(f < nums.size())
        {
            while(s < nums.size() && 1LL * v[f].first > 1LL * 2 * v[s].first){
                update(v[s].second, 1);
                s ++;
            }
            ans += query(nums.size()) - query(v[f].second);
            f++;
        }

        return ans;
    }
};