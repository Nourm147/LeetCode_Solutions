class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int total = 0;

        int n = arr2.size();
        for(int i = 0; i < arr1.size(); i++){
            int ind = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            if(ind < n)
            {
                if(abs(arr1[i] - arr2[ind]) <= d)
                    continue;
            }
            if(ind - 1 >= 0)
            {
                if(abs(arr1[i] - arr2[ind - 1]) <= d)
                continue;
            }
            total ++;
        }

        return total;
    }
};