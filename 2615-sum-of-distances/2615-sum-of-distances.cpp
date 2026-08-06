class Solution {
public:

    struct el{
        long long sum = 0;
        int last = 0;
        int countF = 0;
        int countB = 0;
    };
    vector<long long> distance(vector<int>& nums) {
        map<int, el> mp;
        vector<long long> ans(nums.size());

        for(int i = 0;i < nums.size(); i ++)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = {0, i, 0, 0};
            }
            else{
                auto& p = mp[nums[i]];
                p.countF ++;
                p.sum += p.countF * (i - p.last);
                p.last = i;
            }
        }
        for(int i = nums.size() - 1; i >= 0; i --)
        {
            auto& p = mp[nums[i]];
            
            if(p.countB != 0){
                p.sum -= (p.countF) * (p.last - i);
                p.sum += p.countB * (p.last - i);
                p.countF --;
            }

            p.countB ++;

            ans[i] = p.sum;
            p.last = i;
        }
        return ans;
    }
};