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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        ListNode *pd = &dummy;
        pd->next = head;
        ListNode *ph = head;
        while(ph != NULL){
            if(ph->val == val){
                ListNode *tmp = ph;
                pd->next = ph->next;
                ph = ph->next;
                delete tmp;
            }else{
                pd = pd->next;
                ph = ph->next;
            }
        }
        return dummy.next;
    }
};
