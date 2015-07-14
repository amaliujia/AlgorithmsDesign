class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      if(head == NULL){
        return true; 
      }

      ListNode *fast = head;
      ListNode *slow = head;
      while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
      }

      slow->next = reverseList(slow->next);
      slow = slow->next;
      while(slow != NULL){
        if(head->val != slow->val){
          return false;
        }
        head = head->next;
        slow = slow->next;
      }
      return true;
    }

  private: 
    ListNode *reverseList(ListNode *head){
      ListNode *cur = head;
      ListNode *prev = NULL;
      ListNode *next;

      while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
      return prev;
    }
};
