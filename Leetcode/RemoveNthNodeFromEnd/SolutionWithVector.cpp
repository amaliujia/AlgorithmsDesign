/*
	O(n) time
	O(n) space
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)    return NULL;
        
        vector<ListNode*> v;
        ListNode *dump = new ListNode(-1);
        dump->next = head;
        v.push_back(dump);
        
        while(dump->next != NULL){
            v.push_back(dump->next);
            dump = dump->next;
        }
        
        int size = v.size();
        int index = size - n;
        ListNode *p = v[index - 1];
        ListNode *q = v[index];
        p->next = q->next;
        delete q;
        return v[0]->next;
    }
};
