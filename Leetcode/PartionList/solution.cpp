class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode formerDummy(-1);
        ListNode latterDummy(-1);
        
        ListNode *former = &formerDummy;
        ListNode *latter = &latterDummy;
        
        for(ListNode *curr = head; curr; curr = curr->next){
            if(curr->val < x){
                former->next = curr;
                former = curr;
            }else{
                latter->next = curr;
                latter = curr;
            }
        }
        former->next = latterDummy.next;
        latter->next = NULL;
        return formerDummy.next;
    }
};
