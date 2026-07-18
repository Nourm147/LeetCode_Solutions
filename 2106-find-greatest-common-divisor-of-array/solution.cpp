class Solution {
public:

    int gcdFun(int a, int b){
        if(b == 0)
            return a;

        return gcdFun(b, a % b);
    }

    int findGCD(vector<int>& nums) {

        int mx = 0, mn = INT_MAX;
        for(int i = 0; i < nums.size(); i ++){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }

        return gcdFun(mx, mn);
    }
};
