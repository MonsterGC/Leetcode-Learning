/**
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 * **/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0)
            return res;
        if(n==1)
        {
            res.push_back("()");
            return res;
        }
        string s = "";
        for(int i = 0 ;i < n;++i)
            s+="()";
        sort(s.begin(),s.end());
        do{
            if(IsLegal(s))
                res.push_back(s);
        }while(next_permutation(s.begin()+1,s.end()));
        return res;
    }
    bool IsLegal(string& s)
    {
        int count = 0;
        for(int i = 0;i < s.size();++i)
        {
            if(s[i]=='(')
                count++;
            else
                count--;
            if(count<0)
                return false;
        }
        return true;

    }
};

// Method 1
// class Solution {
// public:
//     void getAns(string str, int left, int right, vector<string>& ans){
//         if(left == 0 && right == 0)
//             ans.push_back(str);
//         if(left > 0)
//             getAns(str + "(", left - 1, right + 1, ans);
//         if(right > 0) 
//            getAns(str + ")", left, right - 1, ans);
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> ans;
//         getAns("", n, 0, ans);
//         return ans;
//     }
// };