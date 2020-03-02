/**
 Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat"). Can you use only one call to the method that checks if one word is a substring of another?

Example 1:

Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True
Example 2:

Input: s1 = "aa", "aba"
Output: False
 

Note:

0 <= s1.length, s1.length <= 100000
 * **/
class Solution
{
public:
    bool isFlipedString(string s1, string s2)
    {
        int len = s1.size();
        if (len != s2.size())
            return false;
        if (len == 0)
            return true;
        string temp = s1 + s1;
        if (temp.find(s2, 0) == -1)
            return false;
        return true;
    }
};