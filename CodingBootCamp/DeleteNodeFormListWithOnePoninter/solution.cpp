struct ListNode {
  int val;
  ListNode *next;
};

//cannot handle the case that delete the last node of linked list.
void deleteNode(ListNode *node) {
  ListNode *temp = node->next;
  node->val = temp->val;
  node->next = temp->next;
  
  free(temp);
}
