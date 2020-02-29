/**
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
 * **/
class Solution
{
public:
    //  left and right Judg
    int typeLiftRight(char s)
    {
        switch (s)
        {
        case '{':
        case '(':
        case '[':
            return -1;
        default:
            return 1;
        }
    }
    // right to left
    char rightToLeft(char s)
    {
        switch (s)
        {
        case '}':
            return '{';
            break;
        case ')':
            return '(';
            break;
        default:
            return '[';
        }
    }
    bool isValid(string s)
    {
        int len = s.size();
        vector<char> result;
        // Can be null
        if (len == 0)
            return true;
        // Odd Numbers don't work
        if (len % 2 == 1)
            return false;
        // It is not allowed to begin with "right"
        if (typeLiftRight(s[0]) == 1)
            return false;
        int start = 0;
        while (start < len)
        {
            if (typeLiftRight(s[start]) == -1)
            {
                // A "left" push was encountered
                result.push_back(s[start]);
            }
            else
            {
                // When "right" is encountered, true=> is pushed
                if (result.back() == rightToLeft(s[start]))
                {
                    result.pop_back();
                }
                else
                {
                    return false;
                }
            }
            start++;
        }

        // Finally, there are no elements in the stack
        if (result.size() == 0)
        {
            return true;
        }

        return false;
    }
};