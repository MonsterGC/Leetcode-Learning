/**
 Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

Example 1:

Input: "aabcccccaaa"
Output: "a2b1c5a3"
Example 2:

Input: "abbccd"
Output: "abbccd"
Explanation: 
The compressed string is "a1b2c2d1", which is longer than the original string.
 

Note:

0 <= S.length <= 50000
 * **/
class Solution {
public:
    string compressString(string S) {
        int len = S.size();
        if(len == 0) return "";
        int start = 0;
        int charLen = 1;
        string result;
        while(start < len){
            if(S[start] == S[start + 1]){
                charLen++;
            }else{
                // result = result + S[start] + to_string(charLen);  // Out of memory limit
                result += S[start] + to_string(charLen);
                charLen=1;
            }
            start++;
        }
        return len > result.size() ? result : S;
    }
};