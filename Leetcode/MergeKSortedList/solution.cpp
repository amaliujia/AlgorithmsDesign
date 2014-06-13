      ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)   return NULL;
        
		return binaryMerge(lists, 0, lists.size()-1);  
      }

      ListNode *binaryMerge(vector<ListNode *> &lists, int left, int right){
          if(left == right) return lists[left];
          if(left > right)  return NULL;
              
          int middle = (left + right) / 2;
          ListNode *l1 = binaryMerge(lists, left, middle);
          ListNode *l2 = binaryMerge(lists, middle + 1, right);
          return mergeTwoLists(l1, l2);
      }
      
      ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
          ListNode head(-1);
          for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next) {
              int val1 = l1 == nullptr ? INT_MAX : l1->val;
              int val2 = l2 == nullptr ? INT_MAX : l2->val;
              if (val1 <= val2) {
                    p->next = l1;
                  l1 = l1->next;
              } else {
                    p->next = l2;
                  l2 = l2->next;
              }
          }
          return head.next;
      }
