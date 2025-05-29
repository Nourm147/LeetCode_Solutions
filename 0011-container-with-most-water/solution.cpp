class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int l = 0, r = height.size() - 1, mArea = 0;
        while (l < r)
        {
            int area = std::min(height[l], height[r]) * (r - l);
            mArea = std::max(mArea, area);
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return mArea;
    }
};
