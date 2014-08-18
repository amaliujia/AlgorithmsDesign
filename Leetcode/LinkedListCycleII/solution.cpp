class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)    return NULL;
        ListNode *slave = head, *master = head;
        while(master->next != NULL && master->next->next != NULL){
            master = master->next->next;
            slave = slave->next;
            if(slave == master){
                break;
            }
        }
        if(!master || master->next == NULL || master->next->next == NULL){
            return NULL;
        }
        slave = head;
        while(slave != master){
            slave = slave->next;
            master = master->next;
        }
        return slave;
    }
};
