/** 12ms
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 * */

class Solution {
public:
    int min(int x, int y){ return x > y ? y : x; }
    int max(int x, int y){ return x > y ? x : y; }
    int findKthMin(vector<int>& nums1,vector<int>& nums2,int k){
        int n=nums1.size(),m=nums2.size();
        int le=max(0,k-m),ri=min(k,n); //划分点le<=i<=ri
        int i,j;
        while(le<ri){
            i=le+(ri-le)/2;
            j=k-i;
            //if(nums1[i-1]<=nums2[j] && nums2[j-1]<=nums1[i]) break; //i==0时nums[i-1]访问未知内存
            if(nums2[j-1]>nums1[i]) le=i+1;
            else ri=i;
        }
        j=k-le;
        if(le==0) return nums2[j-1]; //边界条件
        else if(j==0) return nums1[le-1];
        return max(nums1[le-1],nums2[j-1]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s=nums1.size()+nums2.size();
        if(s%2) return findKthMin(nums1,nums2,s/2+1);
        else return (findKthMin(nums1,nums2,s/2)+findKthMin(nums1,nums2,s/2+1))/2.0;
    }
};