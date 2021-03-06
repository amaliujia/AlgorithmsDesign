class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        ListNode *q;
        p->next = head;
    
        while(p->next != NULL && p->next->next!=NULL){
            q = p->next;
            p->next = p->next->next;
            q->next = p->next->next;
            p->next->next = q;
            
            p = p->next;
        }
    
        return dummy.next;
    }
};

