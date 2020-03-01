/**
 Given two strings,write a method to decide if one is a permutation of the other.

Example 1:

Input: s1 = "abc", s2 = "bca"
Output: true
Example 2:

Input: s1 = "abc", s2 = "bad"
Output: false
Note:

0 <= len(s1) <= 100
0 <= len(s2) <= 100
 * **/
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {

        if(s1.size() != s2.size())
            return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

// 错误做法 =>>>>>> "bbb" & "abc" 过不了
// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2) {
//         int len1 = s1.size();
//         int len2 = s2.size();
//         if(len1 != len2) return false;
//         if(len1 == 0 && len1 == 1) return true;

//         int temp = 0;
//         int start = 0;
//         int result1 = 0;
//         int result2 = 0;
//         while(start < len1){
//             result1 += s1[start];
//             start++;
//         }
//         start = 0;
//         while(start <len2){
//             result2 += s2[start];
//             start++;
//         }

//         return result1 == result2;
//     }
// };