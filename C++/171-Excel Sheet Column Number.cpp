/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
**/
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int temp = 0;
        int octet = s.size() - 1; // 进制位
        for(char x : s){
            temp = x;
            result += pow(26,octet) * (temp - 64);
            octet--;
        }
        return result;
    }
};