class Solution {
public:
    vector<int> v;
    vector<long long> ps;
    int n;
    long long sum = 0;

    bool check(int group)
    {
        for(int i=n-1; i>=0; i--){
            if(group == 0) return true;
            long long s = (long long)group*(long long)(group+1)/2;
            if(s > ps[i + 1]) return false;
            group--;
        }

        return true;
    }

    int maxIncreasingGroups(vector<int>& usageLimits) {

        sort(usageLimits.begin(), usageLimits.end());
        v = usageLimits;
        n = usageLimits.size();
        ps.resize(n + 1, 0);

        for(int i = 0; i < n; i ++){
            sum += v[i];
        }
        
        for(int i = 1; i <= n; i ++){
            ps[i] = ps[i - 1] + v[i - 1];
        }

        long long l = 0, r = n, mid;

        int ans = 0;
        while(l <= r){
            mid = (r + l) >> 1;

            if(check(mid)){
                l = mid + 1;
                ans = mid;
            }else{
                r = mid - 1;
            }
        }

        return ans;
    }
};
