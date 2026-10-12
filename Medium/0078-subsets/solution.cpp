class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int off = 1;
        vector<vector<int>> result (1 << nums.size());
        for(int i = 0; i < nums.size(); i ++)
        {
            int j = off;
            while(j < result.size())
            {
                for(int k = j; k < j + off; k ++)
                    if(k < result.size())
                        result[k].push_back(nums[i]);
                j += 2 * off;
            }
            off *= 2;
        }
        return result;
    }
};
