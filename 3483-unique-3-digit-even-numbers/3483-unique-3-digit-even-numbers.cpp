class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int result = 0;

        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }

        for (int i = 100; i < 999; i += 2) {

            vector<int> curCount(10, 0);
            int temp = i;

            while (temp > 0) {
                curCount[temp % 10]++;
                temp /= 10;
            }
            
            bool isValid = true;
            for (int j = 0; j < 10; j++) {
                if (curCount[j] > count[j]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result++;
            }
        }
        return result;
    }
};