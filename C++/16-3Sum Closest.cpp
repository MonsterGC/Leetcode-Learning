/**
 Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * **/

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len < 3)
            return 0;
        // 排序
        sort(nums.begin(), nums.end());
        int i, low, high;
        int delta = 0x7fffffff, sum, ans;
        for (i = 0; i < len - 2; i++)
        {
            low = i + 1;
            high = len - 1;
            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                if (sum == target)
                {
                    return sum;
                }
                else if (sum < target)
                {
                    if (target - sum < delta)
                    {
                        delta = target - sum;
                        ans = sum;
                    }
                    low++;
                }
                else
                {
                    if (sum - target < delta)
                    {
                        delta = sum - target;
                        ans = sum;
                    }
                    high--;
                }
            }
        }
        return ans;
    }
};