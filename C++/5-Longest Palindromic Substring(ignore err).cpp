/**
 * 
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
**/



/**------------------------------err --> ignore input->"cbbd"  output-> "bb"
 * class Solution {
public:
    string longestPalindrome(string s) {
        int temp = 1;
        int max = 0;
        int LongNum = 0;
        for(int i = 1; i < s.size() - 1; i++){
            LongNum = showLongString(s , i);
            if(i  == 1){
                max =  LongNum;
            }
            if(LongNum > max){
                max=LongNum;
				temp=i;
            }
        }
        return s.substr(temp - max , 2 * max + 1);
    }
    int showLongString(string s , int i){
        int len = 0;
        while(i- len > 0 && i + len < s.size()){
            len++;
            if(s[i-len] != s[i+len]){
                return false;
            }
        }
        return len;
    }
};
**/
// Solution link->https://leetcode-cn.com/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/