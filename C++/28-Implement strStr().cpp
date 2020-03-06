/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
**/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;        
        int target = needle.size();
        if(target == 0) return 0;
        int len = haystack.size();
        if(target > len) return -1;
        
        string temp;
        int i = 0; 
        while(i <= len - target){
            temp = haystack.substr(i, target);
            if(needle==temp){
                return i;
            }
            i++; 
        }
        return -1;
    }
};