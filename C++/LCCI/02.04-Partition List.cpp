/**
 Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

Example:

Input: head = 3->5->8->5->10->2->1, x = 5
Output: 3->1->2->10->5->5->8
 * **/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *first = head;
        ListNode *second = head;
        int temp = 0;
        while (first != NULL)
        {
            if (first->val < x)
            {
                temp = first->val;
                first->val = second->val;
                second->val = temp;
                second = second->next;
            }
            first = first->next;
        }
        return head;
    }
};