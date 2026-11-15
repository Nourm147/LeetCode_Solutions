class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int sum = 0;
        int even = 1, odd = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(sum % 2 == 0){
                even ++;
                ans += odd;
                ans %= (int)(1e9 + 7);
            }
            else{
                odd ++;
                ans += even;
                ans %= (int)(1e9 + 7);
            }
        }
        return ans;
    }
};