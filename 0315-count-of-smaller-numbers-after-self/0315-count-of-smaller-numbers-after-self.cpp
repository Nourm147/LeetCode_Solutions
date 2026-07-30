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

    int q(int i){
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        bit.resize(nums.size() + 1, 0);

        for(int i = 0; i < nums.size(); i ++){
            v.push_back({nums[i], i + 1});
        }

        sort(v.begin(), v.end());
        vector<int> ans(nums.size());

        for(auto p : v)
        {
            update(p.second, 1);
            ans[p.second - 1] = q(nums.size()) - q(p.second);
        }

        return ans;
    }
};