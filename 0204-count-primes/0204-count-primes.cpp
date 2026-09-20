class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> primes(n + 2, true);
        primes[0] = primes[1] = false;
        int count = 1;
        
        for(int i = 3; i * i < n; i += 2)
        {
            if(primes[i]){
                for(int j = i * i; j < n; j += 2 * i)
                    primes[j] = false;
            }
        }

        for(int i = 3; i < n; i += 2)
            if(primes[i]) count ++;

        return count;
    }
};