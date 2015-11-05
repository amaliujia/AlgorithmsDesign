ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if(headA == NULL || headB == NULL) return NULL;

  ListNode *p1 = headA;
  ListNode *p2 = headB;
  while(p1 != p2){
    p1 = p1 == NULL ? headB : p1->next;
    p2 = p2 == NULL ? headA : p2->next;
  }

  return p1 == NULL ? NULL : p1;
}
