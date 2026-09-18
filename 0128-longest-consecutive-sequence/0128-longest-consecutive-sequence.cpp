class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int mx = 0;
        stack<int> pre;
        for(int i = 0; i < nums.size(); i++)
        {
            if(pre.empty())
                pre.push(i);
            if(i == 0)
                continue;
            if(nums[i] != nums[i - 1] + 1)
            {
                mx = max(mx, i - pre.top());
                pre.pop();
                pre.push(i);
            }
        }

        if(!pre.empty())
            mx = max((int) nums.size() - pre.top(), mx);

        return mx;
    }
};