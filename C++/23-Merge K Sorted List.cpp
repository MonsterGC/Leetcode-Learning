/**
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2; //Deal with situations where l1 or l2 has a surplus
        return dummy->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int len = lists.size();
        if (len == 0)
            return NULL;
        if (len == 1)
            return lists[0];

        int i = 0;
        while (i < len - 1)
        {
            lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);
            i++;
        }
        return lists[len - 1];
    }
};

// Method 2
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> longList;
        for (ListNode *start : lists)
        {
            ListNode *ptr = start;
            while (ptr)
            {
                longList.push_back(ptr);
                ptr = ptr->next;
            }
        }
        if (longList.size() == 0)
            return nullptr;
        std::sort(longList.begin(), longList.end(), [](auto x, auto y) { return (x->val) < (y->val); });
        for (size_t i = 0; i < longList.size() - 1; i++)
            longList[i]->next = longList[i + 1];
        longList[longList.size() - 1]->next = nullptr;
        return longList[0];
    }
};