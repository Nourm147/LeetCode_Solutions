class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result;
        while(sum > 0)
        {
            if(sum >= 10)
            {
                result.push_back('0' + 9);
                sum -= 9;
            }else
            {
                result.push_back('0' + sum);
                break;
            }
        }

        int ind = result.size();
        if(ind > num)
            return "";

        while(ind < num){
            result.push_back('0');
            ind ++;
        }

        return result;
    }
};