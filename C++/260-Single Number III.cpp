/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
**/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       vector<int> result;
       int len = nums.size();
       if(len < 2) return nums; 

        // sort
        sort(nums.begin(),nums.end());
        int temp = 0; // Prevents more than three identical Numbers from being present
        bool status = false; // Prevent the number in the first position from being 0
        int i = 0;
        while(i < len){
            if(i + 1 < len){
                if(nums[i] == nums[i+1]){
                    status = true;  
                    temp  = nums[i];
                    i++;
                    continue;
                }
            }
            if(!status){
                result.push_back(nums[i]);
                i++;
                continue;
            }
            if(temp != nums[i]){
                result.push_back(nums[i]);
            }
            i++;
        }
        return result;
    }
};