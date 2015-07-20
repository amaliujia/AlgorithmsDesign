class Solution {
 public:
    ListNode* reverseList(ListNode* head) {
      ListNode *p;
      ListNode *r = reverse(head, p);
      if(r == NULL){
        return NULL;
      }else{
        r->next = NULL;
        return p;
      }
    }
 private:
     ListNode *reverse(ListNode *node, ListNode *& head){
      if(node == NULL){
        return NULL;
      }

      ListNode* r = reverse(node->next, head);
      if(r != NULL){
        r->next = node;
      }else{
        head = node;
      }
      return node;
    }
};
