/**
 Given a string, write a function to check if it is a permutation of a palin­ drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

 

Example1:

Input: "tactcoa"
Output: true（permutations: "tacocat"、"atcocta", etc.）
 * **/

// methods1 0ms
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.size();
        sort(s.begin(), s.end());
        int start = 0;
        bool status = false;
        // Judge parity
        if(len % 2 == 0){
            while(start<len){
                if(s[start] != s[start+1]){
                    return false;
                }
                start+=2;
            }
        }else{
            while(start<len){
                if(status){
                    if(s[start] != s[start+1]){
                        return false;
                    }
                    start+=2;
                }else{
                    if(s[start] != s[start+1]){
                        status = true; // The letter in the middle of the logo                        
                        start++;
                    }else{
                        start+=2;
                    }
                }
            }
        }
        return true;
    }
};

// methods2 4ms
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> dp(128, 0);
        for(char ch : s){
            dp[ch]++;
        }
        int odds = 0;
        for(int val : dp){
            if(val&1){
                odds++;
                if(odds > 1){
                    return false;
                }
            }
        }
        return true;
    }
};