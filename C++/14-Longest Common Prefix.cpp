/**
 Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
 * **/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string s;
        // Not empty array&The only string
        if(len == 0) return "";
        if(len == 1) return strs[0];
        // Traversal string
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < len; j++){
                if( strs[j][i] != strs[0][i] ){
                   return s;
                }
            }
            s = s + strs[0][i];
        }
        return s;
    }
};