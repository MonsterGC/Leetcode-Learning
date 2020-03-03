/**
 Implement an algorithm to find the kth to last element of a singly linked list. Return the value of the element.

Note: This problem is slightly different from the original one in the book.

Example:

Input:  1->2->3->4->5 和 k = 2
Output:  4
Note:

k is always valid.
 * **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// method 1
class Solution
{
public:
    int K = 1;
    int kthToLast(ListNode *head, int k)
    {
        if (head->next == NULL)
            return head->val;
        int val = kthToLast(head->next, k);
        if (K++ >= k)
        {
            return val;
        }
        else
        {
            return head->val;
        }
    }
};

// method 2
class Solution
{
public:
    int K = 1;
    int kthToLast(ListNode *head, int k)
    {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *first = result;
        ListNode *second = result;

        for (int i = 0; i < k + 1; i++)
        {
            first = first->next;
        }
        while (first != NULL)
        {
            first = first->next;
            second = second->next;
        }
        return second->next->val;
    }
};