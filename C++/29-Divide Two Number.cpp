/**
 Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
 * **/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if( dividend > INT_MIN ) return -dividend;
            return INT_MAX;
        }
        long a = dividend;
        long b = divisor;
        int sign = 1; 
        if((a > 0 && b < 0) || ( a < 0 && b > 0)){
            sign = -1;
        }
        a = a > 0?a : -a;
        b = b > 0?b : -b;
        long res = div(a , b);
        if( sign > 0 ) return res > INT_MAX?INT_MAX : res;
        return -res;
    }
    int div(long a, long b){ 
        if(a < b) return 0;
        long count = 1;
        long tb = b;
        while((tb << 1)<=a){
            count = count << 1;
            tb = tb << 1;
        }
        return count + div(a-tb,b);  // Keep narrowing the margin of error
    }
};