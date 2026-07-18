class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long mul = 1;
        int lastN = 0;
        int lastP = 0;
        bool zero = false;
        bool one = false;

        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] != 0)
                mul *= nums[i];
            else
                zero = true;

            if(nums[i] == 1)
                one = true;

            if(nums[i] < 0)
                lastN = nums[i];

            if(nums[i] > 0)
                lastP = nums[i];
        }

        if(lastP == 0 && lastN == 0)
            return 0;

        if(mul > 0)
            return mul;

        if(lastP == 0 && zero && mul / lastN == 1 && !one)
            return 0;
            
        if(lastN != 0 && (mul / lastN != 1 || one))
            return mul / lastN;
    
        return mul;
            
    }
};
