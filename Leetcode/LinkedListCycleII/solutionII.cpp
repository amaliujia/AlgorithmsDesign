ListNode *findCycle(ListNode *head){
  if(head == NULL || head->next == NULL) return NULL;

  ListNode *slow = head;
  ListNode *fast = head;
  do{
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      break;
    }
  }while(fast != NULL && fast->next != NULL);

  if(fast == NULL || fast->next == NULL){
    return NULL;
  }

  slow = head;
  while(slow != fast){
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}
