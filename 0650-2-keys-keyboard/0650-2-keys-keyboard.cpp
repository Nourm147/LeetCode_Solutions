class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;

        int sum = 0;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0){
                int count = 0;
                while(n % i == 0){
                    n /= i;
                    count++;
                }
                sum += count * i;
            }
        }
        if(n != 1)
            sum += n;
        
        return sum;
    }
};