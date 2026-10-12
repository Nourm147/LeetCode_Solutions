class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> v;
        for(int i = 1; i * i <= n; i ++){
            if(n % i == 0){
                v.push_back(i);
            }
        }
        for(int i = v.size() - 1; i >= 0; i --){
            if(n / v[i] != v[i])
                v.push_back(n / v[i]);
        }

        if(k <= v.size())
            return v[k - 1];
        return -1;
    }
};
