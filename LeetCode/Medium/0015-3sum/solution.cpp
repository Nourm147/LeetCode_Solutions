
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int target = -nums[i];
            int start = i + 1, end = nums.size() - 1;
            while (start < end)
            {
                if (target > nums[start] + nums[end])
                {
                    start++;
                }
                else if (target < nums[start] + nums[end])
                {
                    end--;
                }
                else
                {
                    result.push_back({nums[i], nums[start], nums[end]});
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

        return result;
    }
};

