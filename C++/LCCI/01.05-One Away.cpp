/**
 There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

 

Example 1:

Input: 
first = "pale"
second = "ple"
Output: True
Example 2:

Input: 
first = "pales"
second = "pal"
Output: False
 * **/
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first == second) return true;
        int len1 = first.size();
        int len2 = second.size();
        if(len1 - len2 > 1) return false;
        int start = 0;
        bool status = false;  // Record error times
        if(len1 == len2){
            while(start < len1){
                if(first[start] != second[start]){
                    if(!status){
                        status = true;
                    }else{
                        return false;
                    }
                }
                start++;
            }
        }else{
            if(len1<len2){ // The first length is greater than the second length
                return oneEditAway(second,first);
            }
            while(start < len1){
                if(!status){
                    if(first[start] != second[start]){
                        status = true;
                    }
                }else{
                    if(first[start] != second[start-1]){
                        return false;
                    }
                }
                start++;
            }
        }
        return true;
    }
};