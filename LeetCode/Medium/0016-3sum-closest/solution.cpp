class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        int closest = nums[0] + nums[1] + nums[2], howClose = abs(closest - target);

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int targetSum = target - nums[i];
            int start = i + 1, end = nums.size() - 1;
            while (start < end)
            {
                int twoSum = nums[start] + nums[end];
                if (howClose > abs(targetSum - twoSum))
                {
                    howClose = abs(targetSum - twoSum);
                    closest = nums[i] + twoSum;
                }
                if (targetSum > twoSum)
                {
                    start++;
                }
                else if (targetSum < nums[start] + nums[end])
                {
                    end--;
                }
                else
                {
                    return target;
                }
            }
        }
        return closest;
    }
};
