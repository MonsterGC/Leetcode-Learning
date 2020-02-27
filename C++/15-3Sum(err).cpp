/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 * **/
class Solution
{
public:
    // 去重
    bool isEqual(vector<int> &temp, int x, int y, int z)
    {
        int lenTemp = temp.size();
        if (lenTemp != 3)
        {
            return false;
        }
        if (temp[0] == x)
        {
            if (temp[1] == y)
            {
                if (temp[2] == z)
                {
                    return true;
                }
            }
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        vector<vector<int>> result;
        int temp = 0;
        // 排序
        sort(nums.begin(), nums.end());
        for (int x = 0; x < len - 2; x++)
        {
            for (int y = x + 1; y < len - 1; y++)
            {
                for (int z = y + 1; z < len; z++)
                {
                    if (nums[x] + nums[y] + nums[z] == 0)
                    {
                        for (int i = 0; i < result.size(); i++)
                        {
                            if (isEqual(result[i], nums[x], nums[y], nums[z]))
                            {
                                continue;
                            }
                        }
                        result.push_back(vector<int>{nums[x], nums[y], nums[z]});
                    }
                }
            }
        }
        return result;
    }
};