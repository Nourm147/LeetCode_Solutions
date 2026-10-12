class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int currentTrack = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                continue;
            }
            nums[currentTrack] = nums[i];
            currentTrack++;
        }
        return currentTrack;
    }
};
