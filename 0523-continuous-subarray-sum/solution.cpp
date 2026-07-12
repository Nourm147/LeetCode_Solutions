class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long long, int> mp;
        long long sum = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp[sum % k] != 0)
            {
                if(mp[sum % k] == i + 1)
                    continue;
                else
                    return true;
            }else{
                mp[sum % k] = i + 2;
            }
        }

        return false;
    }
};
