class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(n <= m){
        return head;
      } 

      ListNode dummy(-1);
      dummy.next = head;
      ListNode *cur = &dummy;
      int count = 0;

      while(count < (m-1) && cur->next != NULL){
        count++;
        cur = cur->next;
      }

      if(cur->next == NULL){
        return head;
      }

      ListNode *nh = cur;
      ListNode *prev = cur->next;
      ListNode *temp = NULL;
      cur = prev->next;
      for(int i = m + 1; i <= n; i++){
        if(cur == NULL){
          break;
        }

        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
      }

      nh->next->next = cur;
      nh->next = prev;
      return dummy.next;

    }
};
