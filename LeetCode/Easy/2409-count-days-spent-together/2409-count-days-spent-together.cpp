class Solution {
public:

    vector<int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int preM[13];
    
    int getDate(string date)
    {
        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day = (date[3] - '0') * 10 + (date[4] - '0');
        return preM[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        preM[0] = 0;
        for(int i = 1; i <= 12; i++)
        {
            preM[i] = preM[i - 1] + months[i - 1];
        }

        int dA1 = getDate(arriveAlice);
        int dA2 = getDate(leaveAlice);
        int dB1 = getDate(arriveBob);
        int dB2 = getDate(leaveBob);

        int mn = min({dA2 - dB1, dB2 - dA1, dA2 - dA1, dB2 - dB1}) + 1;
        return max(mn, 0);
    }
};