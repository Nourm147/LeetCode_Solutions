class Solution {
public:

    int reverse(int num){
        int res = 0;
        while(num != 0)
        {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for(int i = nums.size() - 1; i >= 0; i --){
            int elem = reverse(nums[i]);

            if(mp.find(elem) != mp.end()){
                ans = min(ans, abs(mp[elem] - i));
            }
            
            mp[nums[i]] = i;
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
