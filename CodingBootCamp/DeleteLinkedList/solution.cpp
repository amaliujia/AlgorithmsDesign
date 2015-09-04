
void deleteLinkedList(ListNode **head){
  ListNode *cur = *head;
  ListNode *next = NULL;

  while(cur != NULL){
    next = cur->next;
    free(cur);
    cur = next;
  }

  *head = NULL;
}
