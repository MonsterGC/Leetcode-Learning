#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        unordered_map<int, int> hash;
        int temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.begin() != nums.end())
            {
                temp = target - nums[i];
                if (hash.count(temp))
                {
                    result = vector<int>({hash[temp], i});
                    break;
                }
                hash[nums[i]] = i;
            }
        }
        return result;
    }
};