class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> fr(32, 0);

        for(int i = 0; i < nums.size(); i ++)
        {
            for(int j = 31; j >= 0; j --)
            {
                if(((nums[i] >> j) & 1) == 1){
                    fr[j]++;
                }
            }
        }

        int result = 0;
        for(int i = 0; i < 32; i ++){
            if(fr[i] % 3 != 0)
                result += (1 << i);
        }

        return result;
    }
};