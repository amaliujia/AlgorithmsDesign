class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)    return;
        
        ListNode dummy(-1);
        ListNode *pdummy = &dummy;
        ListNode *slave, *king;
        pdummy->next = head;
        slave = pdummy;
        king = pdummy;
        
        while((king->next != NULL) && (king->next->next != NULL)){
            slave = slave->next;
            king = king->next->next;
        }
        
        pdummy = slave;
        slave = slave->next;
        pdummy->next = NULL;
        slave = reverseList(slave);
        pdummy = &dummy;
        king = pdummy->next;
        while(king != NULL){
            pdummy->next = king;
            king = king->next;
            pdummy = pdummy->next;
            pdummy->next = slave;
            slave = slave->next;
            pdummy = pdummy->next;
        }
        
        while(slave != NULL){
            pdummy->next = slave;
            slave = slave->next;
            pdummy = pdummy->next;
        }
    }
private:
    ListNode *reverseList(ListNode *head){
        if(head == NULL)    return NULL;
        
        ListNode *prev, *curr, *next;
        prev = head;
        curr = head->next;
        prev->next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;        
    }
};

