/*
	O(n) time
	O(n) space
*/
ListNode* reverseKGroup(ListNode* head, int k) {
  if(head == NULL || head->next == NULL || k < 2){
    return head;
  }

  ListNode *p = head;
  for(int i = 0; i < k; i++){
    if(p != NULL){
      p = p->next;
    }else{
      return head;
    }
  }


  ListNode *ghead = reverseKGroup(p, k);
  ListNode *cur = head, *prev = NULL, *next;

  while(cur != p){
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  head->next = ghead;
  return prev;
}
