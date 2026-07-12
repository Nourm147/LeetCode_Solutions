class Solution {
public:
    int maxProduct(vector<int>& A) {
        int ans = A[0], dpMin = A[0], dpMax = A[0];
        for(int i = 1; i < size(A); i++) {
            auto prevDpMin = dpMin, prevDpMax = dpMax;
            dpMin = min(A[i], A[i] * (A[i] >= 0 ? prevDpMin : prevDpMax));
            dpMax = max(A[i], A[i] * (A[i] >= 0 ? prevDpMax : prevDpMin));
            ans = max(ans, dpMax);
        }
        return ans;
    }
};
