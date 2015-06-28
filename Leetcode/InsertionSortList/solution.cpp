/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* insertionSortList(ListNode* head) {
      ListNode *dummy = new ListNode(-1);
      while(head != NULL){
        ListNode *cur = dummy;
        bool inserted = false;
        while(cur->next != NULL){
          if(cur->next->val > head->val){
            ListNode *tmp = new ListNode(head->val);
            tmp->next = cur->next;
            cur->next = tmp;
            inserted = true;
            break;
          }
          cur = cur->next;
        }
        if(!inserted){
          cur->next = new ListNode(head->val);
        }

        head = head->next;
      }
      return dummy->next;
    }
};
