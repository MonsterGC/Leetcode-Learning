/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * **/

// Greedy algorithm ==============>Method 1
class Solution {
public:
    string intToRoman(int num) {
        string result;
        int index=0;
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        while(index < 13){ 
            while( num >= nums[index] ){ 
                result = result + romans[index]; 
                num -= nums[index];
            } 
            index++; 
        }
        return result;
    }
};

// One-to-one matching ==================>Method 2
class Solution
{
public:
    string rule(int num)
    {
        switch (num)
        {
        case 1:
            return "I";
            break;
        case 2:
            return "II";
            break;
        case 3:
            return "III";
            break;
        case 4:
            return "IV";
            break;
        case 5:
            return "V";
            break;
        case 6:
            return "VI";
            break;
        case 7:
            return "VII";
            break;
        case 8:
            return "VIII";
            break;
        case 9:
            return "IX";
            break;
        case 10:
            return "X";
            break;
        case 20:
            return "XX";
            break;
        case 30:
            return "XXX";
            break;
        case 40:
            return "XL";
            break;
        case 50:
            return "L";
            break;
        case 60:
            return "LX";
            break;
        case 70:
            return "LXX";
            break;
        case 80:
            return "LXXX";
            break;
        case 90:
            return "XC";
            break;
        case 100:
            return "C";
            break;
        case 200:
            return "CC";
            break;
        case 300:
            return "CCC";
            break;
        case 400:
            return "CD";
            break;
        case 500:
            return "D";
            break;
        case 600:
            return "DC";
            break;
        case 700:
            return "DCC";
            break;
        case 800:
            return "DCCC";
            break;
        case 900:
            return "CM";
            break;
        case 1000:
            return "M";
            break;
        case 2000:
            return "MM";
            break;
        case 3000:
            return "MMM";
            break;
        default:
            return "";
        }
    }
    string intToRoman(int num)
    {
        string result;
        int i = 1;
        while (num != 0)
        {
            cout << (num % 10) * i;
            result = rule((num % 10) * i) + result; // The left and right of result matter
            i *= 10;
            num /= 10;
        }
        return result;
    }
};