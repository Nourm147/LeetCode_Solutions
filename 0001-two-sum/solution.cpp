class Solution
{

public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::map<int, int> numMap;

        for (int i = 0, n = nums.size(); i < n; i++)
        {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end())
            {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};
