class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> result;
        long long int test;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                long long twoSum = nums[i] + nums[j];
                long long targetSum = target - twoSum;
                int start = j + 1, end = nums.size() - 1;
                while (start < end)
                {
                    if (targetSum > nums[start] + nums[end])
                    {
                        start++;
                    }
                    else if (targetSum < nums[start] + nums[end])
                    {
                        end--;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while (start < end && nums[start] == nums[start + 1])
                        {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end - 1])
                        {
                            end--;
                        }
                        start++;
                        end--;
                    }
                }
            }
        }

        return result;
    }
};
