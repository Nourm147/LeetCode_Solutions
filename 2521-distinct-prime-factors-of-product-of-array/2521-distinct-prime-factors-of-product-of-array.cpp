class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {

        set<int> s;
        for(int j = 0; j < nums.size(); j++){
            for(int i = 2; i * i <= nums[j]; i++){
                if(nums[j] % i == 0)
                {
                    s.insert(i);
                    while(nums[j] % i == 0)
                        nums[j] /= i;
                }
            }
            if(nums[j] != 1)
                s.insert(nums[j]);
        }

        return s.size();
    }
};