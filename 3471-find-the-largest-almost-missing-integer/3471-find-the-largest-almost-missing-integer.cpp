class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i ++){
            mp[nums[i]]++;
        }

        if(k == 1)
        {
            int mx = -1;
            for(auto p : mp){
                if(p.second == 1)
                    mx = max(mx, p.first);
            }
            return mx;
        }

        int a = nums[nums.size() - 1], b = nums[0];
        if(a < b)
            swap(a, b);
        if(mp[a] == 1)
            return a;
        else if(mp[b] == 1)
            return b;
        else
            return -1;
    }
};