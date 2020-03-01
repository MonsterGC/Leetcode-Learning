/**
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string. (Note: If implementing in Java,please use a character array so that you can perform this operation in place.)

Example 1:

Input: "Mr John Smith ", 13
Output: "Mr%20John%20Smith"
Explanation: 
The missing numbers are [5,6,8,...], hence the third missing number is 8.
Example 2:

Input: "               ", 5
Output: "%20%20%20%20%20"
 

Note:

0 <= S.length <= 500000
**/

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string result;
        // for(int i = 0;i<length;i++){  ==>72ms
        //     if(i < S.size()){
        //         if(S[i] == ' '){
        //             result +="%20";
        //         }else{
        //             result += S[i];
        //         }
        //     }else{
        //         result += "%20";
        //     }
        // }

        // ====> 56ms
        for(int i = 0;i<length;i++){
            if(S[i] != ' ')
                result.push_back(S[i]); // push_back a character to the end
            else{
                result.append("%20"); //append a c-string to string
            }
        }
        return result;
    }
};