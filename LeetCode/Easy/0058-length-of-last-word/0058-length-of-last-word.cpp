class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool found = false;
        for(int i = s.size() - 1; i >= 0; i --)
        {
            if(!found && s[i] == ' ')
                continue;
            else if(s[i] != ' ')
            {
                found = true;
                count ++;
            }else if(s[i] == ' ' && found){
                break;
            }
        }
        return count;
    }
};