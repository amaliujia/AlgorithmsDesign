/*
 * nlogk, better than nlogn two-way merge sort.
 */ 
class Solution {
  private:
    struct compare{
      bool operator()(const ListNode *l1, const ListNode *l2){
        return l1->val > l2->val;
      } 
    };

  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;

      for(auto l : lists){
        if(l){
          min_heap.push(l);
        }
      }

      ListNode dummy(-1);
      ListNode *dh = &dummy;
      ListNode *cur = NULL;
      while(!min_heap.empty()){
        cur = min_heap.top();
        min_heap.pop();
        dh->next = cur;
        if((cur)->next){
          min_heap.push(cur->next);
        }
        dh = cur;
      }

      return dummy.next;
    }
};
