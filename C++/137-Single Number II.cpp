/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
**/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        
        sort(nums.begin(),nums.end());
        int temp = 0; 
        bool status = false; 
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
            if(!status || temp != nums[i]){
                return nums[i];
            }
            i++;
        }
        return 0;
    }
};