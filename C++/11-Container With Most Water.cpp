/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

IMAGE:https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
 * **/

// 12ms
class Solution {
public:
    int maxArea(vector<int>& height) {
    int res = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
        int area = (j - i) * min(height[i], height[j]);
        res = max(res, area);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
    }
};


/** 24 ms ====================>add defined max&min function
 * class Solution {
public:
    int maxInt(int x , int y){ return x >= y ? x : y; }
    int minInt(int x , int y){ return x >= y ? y : x; }
    int maxArea(vector<int>& height) {
    int res = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
        int area = (j - i) * minInt(height[i], height[j]);
        res = maxInt(res, area);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
    }
};
 * **/
