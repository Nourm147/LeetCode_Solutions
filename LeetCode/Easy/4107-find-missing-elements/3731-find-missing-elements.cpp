class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto mn = min_element(nums.begin(), nums.end());
        auto mx = max_element(nums.begin(), nums.end());
        
        set<int> s;
        for(int i = 0; i < nums.size(); i ++)
        {
            s.insert(nums[i]);
        }

        vector<int> v;
        for(int i = *mn; i < *mx; i ++)
        {
            if(!s.contains(i))
                v.push_back(i);
        }

        return v;
    }
};