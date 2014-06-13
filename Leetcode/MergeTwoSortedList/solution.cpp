// worst case O(max(m,n)) time
// average case O(min(m, n) time
// O(1) space
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        
        ListNode dummy(-1);
        ListNode *temp = &dummy;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        (l1 == NULL) ? temp->next = l2 : temp->next = l1;
        return dummy.next;
    }
};
