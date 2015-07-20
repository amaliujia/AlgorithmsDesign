class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0){
            return head;
        }
        
        int len = 1;
        ListNode *p = head;
        while(p->next != NULL){
            p = p->next;
            len++;
        }
        
        len = len - k % len;
        p->next = head;
        int i = 0;
        while(i < len){
            p = p->next;
            i++;
        }
        
        ListNode *prev = p->next;
        p->next = NULL;
        return prev;
    }
};
