/**
 * Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
 * **/
class Solution {
public:
    int myAtoi(string str) {
        int end = 0; // Space end position
        double result = 0;
        
        // Locate the header to the end of the space
        for(int i = 0 ; i< str.length(); i++){
            if(str[i] != ' '){
                end = i;
                break;
            }
        }

        int status = str[end] == '-' ? -1 : 1; // Test sign
        for(int j = end; j< str.length();j++){
            if((status == -1 || str[end] == '+') && j == end) continue; // Determine if the first position has a +/-
            if(str[j] < 48 || str[j] > 57) break; // End with letter
            result = result * 10 + (int)(str[j] - '0'); // Character to int

            // Exception handling 
            if(status == -1){
				if(result * status < INT_MIN)  return INT_MIN;	
			}else{
				if(result > INT_MAX) return INT_MAX;
			}
        }

        /** There are numerical particularly big 200000000000000000000000... This overflow handling is not feasible
         * 
        result *=status;
        if(result >= INT_MIN && result <= INT_MAX){
            return result;
        }else if(result < INT_MIN){
            return INT_MIN;
        }else{
            return INT_MAX;
        }
         * **/
        return status * result;
    }
};