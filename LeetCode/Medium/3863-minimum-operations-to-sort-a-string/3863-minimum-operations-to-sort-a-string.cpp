class Solution {
public:
    int minOperations(string s) {

        if(is_sorted(s.begin(), s.end()))
            return 0;

        int mx = *max_element(s.begin(), s.end()), mn = *min_element(s.begin(), s.end());
        if(s[0] == mn || s[s.size() - 1] == mx)
        {
            return 1;
        }
        if(s.size() == 2)
            return -1;

        for(int i = 1; i < s.size() - 1; i ++){
            if(s[i] == mx || s[i] == mn)
                return 2;
        }
        return 3;

    }
};