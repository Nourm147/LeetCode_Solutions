class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
 
        for(int i = 0; i < arr.size(); i++){
            arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
        }
        return arr;
    }
};
