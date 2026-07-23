class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2)
            return n;

        int mul = 1;

        while(n != 0){
            mul *= 2;
            n = n >> 1;
        }

        return  mul;
    }
};
