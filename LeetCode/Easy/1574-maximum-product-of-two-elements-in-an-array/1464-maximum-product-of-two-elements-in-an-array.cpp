class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> v(2, 0);
        int j = 0;
        for(int i = 0; i < nums.size(); i ++){
            j = 0;
            if(v[1] < v[0])
                j = 1;
        
            v[j] = max(v[j], nums[i] - 1);
        }

        return v[0] * v[1];
    }
};