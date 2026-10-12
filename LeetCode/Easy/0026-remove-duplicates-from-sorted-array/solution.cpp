class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int currentTrack = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            nums[currentTrack] = nums[i];
            currentTrack++;
        }
        return currentTrack;
    }
};
