class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode dummy(-1);
      ListNode *dp = &dummy;
      dp->next = head;
      
      ListNode *cur = dp->next;
      ListNode *prev = dp;
      if(cur == NULL)   return cur;
      int a = cur->val;
      while(cur->next != NULL){
          if(cur->next->val != a){
              prev = cur;
              cur = cur->next;
              a = cur->val;
          }else{
              ListNode *temp = cur;
              cur = cur->next;
              prev->next = cur;
              delete temp;
              
              while(cur != NULL){
                  if(cur->val == a){
                    ListNode *temp = cur;
                    cur = cur->next;
                    prev->next = cur;
                    delete temp;  
                  }else{
                      break;
                  }
              }
              cur = prev;
          }
      }
      return dp->next;
    }
};
