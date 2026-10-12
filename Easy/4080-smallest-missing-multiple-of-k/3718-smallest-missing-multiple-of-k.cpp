class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i ++){
            s.insert(nums[i]);
        }

        int cand = k;
        while(true){
            if(s.find(cand) == s.end())
                break;
            cand += k;
        }
        return cand;
    }
};