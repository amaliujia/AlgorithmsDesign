class Solution {
  public:
    void deleteNode(ListNode* node) {
      if(node == NULL || node->next == NULL){
        return;
      }

      node->val = node->next->val;
      ListNode *p = node->next;
      node->next = node->next->next;
      delete p;
    }
};
