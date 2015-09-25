class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
      if(head == NULL || head->next == NULL){
        return head;
      }

      ListNode *temp = swapPairs(head->next->next);
      ListNode *temp2 = head->next;
      head->next = temp;
      temp2->next = head;
      return temp2;
    }
};
