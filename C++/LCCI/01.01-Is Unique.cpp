/**
 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

Example 1:

Input: s = "leetcode"
Output: false
Example 2:

Input: s = "abc"
Output: true
 

Note:

0 <= len(s) <= 100
 * **/
class Solution {
public:
    bool isUnique(string astr) {
        vector<int> result(200);
        int len = astr.size();

        int charToInt = 0;
        for(int i = 0; i<len;i++){
            charToInt = astr[i];
            if(result[charToInt] == 0){
                result[charToInt] = 1;
            }else{
                return false;
            }
        }
        return true;
    }
};