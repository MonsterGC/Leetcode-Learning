/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
**/
// Method 1 ==> XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);

        int num = nums.size();
        for(int i = 0; i < nums.size(); i++){
            num ^= i^nums[i];
        }
        return num;
    }
};

// Method 2 sort=>filter
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios::sync_with_stdio(false);

        int len = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++ ){
            if(nums[i+1] - nums[i] != 1){
                return nums[i] + 1;
            }
        }
        return nums[0] == 0 ? nums[len - 1] + 1 : 0;
    }
};

// Method 3 Math
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = nums.size()*(nums.size() + 1)/2;
        int actualSum = 0;
        for (int num : nums) actualSum += num;
        return expectedSum - actualSum;
    }
};

// Method Hash