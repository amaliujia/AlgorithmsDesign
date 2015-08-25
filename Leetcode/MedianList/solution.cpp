int medianOfList(ListNode *head) {
  if (head == NULL) {
    return -1; 
  }
  
  if (head->next == NULL) {
    return head->val;
  }

  ListNode *fast = head, *slow = head;

  while(fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  } 

  return slow->val;
}
