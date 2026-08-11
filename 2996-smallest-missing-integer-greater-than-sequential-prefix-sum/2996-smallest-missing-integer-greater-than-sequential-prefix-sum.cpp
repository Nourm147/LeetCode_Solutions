class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int mxSum = 0;
        int mxLen = 0;
        int sum = 0;
        int len = 0;
        set<int> s;
        for(int i = 0; i < nums.size(); i ++)
            s.insert(nums[i]);

        bool found = false;
        for(int i = 0; i < nums.size() - 1; i ++){
            if(nums[i] == nums[i + 1] - 1){
                len ++;
                sum+=nums[i];
            }else
            {
                len ++;
                sum += nums[i];
                if(len > mxLen)
                {
                    len = mxLen;
                    mxSum = sum;
                }
                len = 0;
                sum = 0;
                found = true;
                break;
            }
        }
        if(!found){
            len ++;
            sum += nums[nums.size() - 1];
            if(len > mxLen)
            {
                len = mxLen;
                mxSum = sum;
            }
        }
        while(true)
        {
            if(s.find(mxSum) == s.end())
                return mxSum;
            mxSum++;
        }
        return -1;
    }
};