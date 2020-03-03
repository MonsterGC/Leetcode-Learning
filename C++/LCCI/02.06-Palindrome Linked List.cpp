/**
 Implement a function to check if a linked list is a palindrome.

 

Example 1:

Input:  1->2
Output:  false 
Example 2:

Input:  1->2->2->1
Output:  true 
 

Follow up:
Could you do it in O(n) time and O(1) space?
 * **/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next ==NULL) return true;
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        int vLen = v.size();
        for(int i=0; i<vLen/2; i++) {
            if(v[i] != v[vLen-1-i]) return false;
        }
        return true;
    }
};