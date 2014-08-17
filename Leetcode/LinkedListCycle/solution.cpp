// O(n) time
// O(1) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *master = &dummy;
        ListNode *slave = &dummy;
        while(master->next != NULL && master->next->next != NULL){
            master = master->next->next;
            slave = slave->next;
            if(master == slave){
                return true;
            }
        }
        return false;
    }
};
