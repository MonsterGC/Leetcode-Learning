/**
 找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 * **/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if( nums.empty() ) return -1;
        ios::sync_with_stdio(false);
		// 方法一
        // vector<int> result(100000,0);
		// for (int i = 0; i < nums.size(); i++) {
		// 	result[nums[i]]++;
		// 	if (result[nums[i]] == 2) {
		// 		return nums[i];
		// 	}
		// }
        // 方法二
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        // 方法三
        // for (int i = 0; i < nums.size(); ++i) {
        //     while (nums[i] != i) {
        //         if (nums[nums[i]] == nums[i]) return nums[i];
        //         swap(nums[i], nums[nums[i]]);
                
        //     }
        // }
        return -1;
    }
};