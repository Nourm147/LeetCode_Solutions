class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            result += nums[i] - nums[0];
        }
        return result;
    }
};