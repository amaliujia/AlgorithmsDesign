class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
       if(head == NULL || head->next == NULL) return head;
       int count = 0;
       ListNode dummy(-1);
       dummy.next = head;
       ListNode *p = &dummy;
       while(count < m - 1 && p != NULL){
           count++;
           p = p->next;
       }
       
       if(p == NULL)    return head;
       ListNode *connection = p;
       ListNode *prev = p->next;
       p = prev->next;
       
       for(int i = m; i < n; i++){
           prev->next = p->next;
           p->next = connection->next;
           connection->next = p;
           p = prev->next;
       }
       return dummy.next;
    }
};
