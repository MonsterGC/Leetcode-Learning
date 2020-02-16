
/** 4ms
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pst;
        pst=l1;
        l1->val+=l2->val;
        int nst=l1->val/10;
        l1->val%=10;
        while(l1 -> next!=NULL && l2-> next!=NULL){
            l1=l1->next;
            l2=l2->next;
            l1->val=l1->val+l2->val+nst;
            nst=l1->val/10;
            l1->val%=10;
        }
        while(l1->next==NULL&&l2->next!=NULL){
            l2=l2->next;
            l1->next=new ListNode(l2->val+nst);
            l1=l1->next;
            nst=l1->val/10;
            l1->val%=10;
        }
        while(nst>0){
            if(l1->next==NULL) l1->next=new ListNode(nst);
            else l1->next->val+=nst;
            l1=l1->next;
            nst=l1->val/10;
            l1->val%=10;
        }
        return pst;
    }
};

/** 16ms
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode result(0);
        ListNode *p = &result;
        int carry = 0;
        while(l1!=NULL && l2!=NULL)
        {
            int num = l1->val + l2->val + carry;
            carry = num/10;
            p->next = new ListNode(num%10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l2!=NULL)
            l1 = l2;
        while(l1!=NULL)
        {
            int num = l1->val + carry;
            carry = num/10;
            p->next = new ListNode(num%10);
            p = p->next;
            l1 = l1->next;
        }
        if(carry)
            p->next = new ListNode(carry);
        return result.next;        
    }
};



/**
 * ---------------------------------------------------------
 * 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;
        int len2 = 1;
        ListNode* p = l1;
        ListNode* q = l2;

        while(p->next !=NULL || q->next != NULL){
            if(p->next !=NULL && q->next != NULL){
                len1++;
                len2++;
                p = p->next;
                q = q->next;
            }
            if(p->next != NULL && q->next == NULL){
                len1++;
                p = p->next; 
            }

            if(q->next != NULL && p->next == NULL){
                len2++;
                q = q->next; 
            }
        };

        ListNode* l3;
        if(len2 > len1){
            for(int i = 0;i<len2;i++){
                if(i+1 >= len1){
                    l3->val = 0 + q->val;
                }else{
                    l3->val = p->val + q->val;
                    p = p->next; 
                }
                q = q->next;
                l3 = l3->next;
            }
        }

        if(len2 = len1){
            for(int i = 0;i<len2;i++){
                l3->val = p->val + q->val;
                p = p->next;
                q = q->next;
                l3 = l3->next;
            }
        }

        if(len1 > len2){
            for(int i = 0;i<len1;i++){
                if(i+1 >len2){
                    l3->val = 0 + q->val;
                }else{
                    l3->val = p->val + q->val;
                    q = q->next; 
                }
                p = p->next;
                l3 = l3->next;
            }
        }
        return l3;
    }
};
*/