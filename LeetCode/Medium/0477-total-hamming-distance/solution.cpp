class Solution {
public:

    vector<pair<int, int>> v;

    void totalones(int num){
        for(int i = 0; i < 32; i ++){
            if(num & 1){
                v[i].second ++;
            }else{
                v[i].first ++;
            }
            num = num >> 1;
        }
    }

    int totalHammingDistance(vector<int>& nums) {

        v.resize(32, {0, 0});

        for(int i = 0; i < nums.size(); i++)
            totalones(nums[i]);

        int count = 0;
        for(int i = 0; i < 32; i ++)
            count += v[i].first * v[i].second;

        return count;
    }
};
