class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start = 0;
        long long sum = 0;
        long long check = 0;
        int len = 0;
        int maxlen = 0;

        int i = 0;
        while(i < nums.size())
        {
            if(sum == check){
                sum += nums[i];
                check ^= nums[i];
                if(sum == check)
                    maxlen = max(maxlen, i - start + 1);
                i++;
            }
            else{
                while(sum != check){
                    sum -= nums[start];
                    check ^= nums[start];
                    start ++;
                }
            }
        }

        return maxlen;
    }
};
