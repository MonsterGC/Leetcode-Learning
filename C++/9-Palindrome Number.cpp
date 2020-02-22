/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
 * **/

class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        int len = 0;
        // Negative Numbers don't match
        if(x < 0) return false;
        if(x < 9) return true;
        
        // Since the length of an array can be directly determined, using a vector incurs additional overhead
        // vector<int> num;

        // determine the length
        while(n != 0){
            // num.push_back(x % 10);
            len++;
            n /=10;
        }
        
        // Defines an array that holds Numbers
        int num[len];
        for(int i = 0; i < len ; i++){
        	num[i] = x % 10;
            x /= 10;	
        }

        // Whether the symmetric positions are equal
        int start = 0;
        int end = len - 1;
        while(start <= end){        	
            if(num[start] != num[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};