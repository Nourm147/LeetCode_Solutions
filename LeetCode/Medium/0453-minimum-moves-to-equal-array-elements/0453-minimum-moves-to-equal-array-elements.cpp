class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        int mn = *min_element(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            result += nums[i] - mn;
        }
        return result;
    }
};