/*
	O(n) time
	O(1) space
*/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return NULL;
        int guard;
		guard = head->val;
        ListNode *cursor = head;
		ListNode *temp;
        while(cursor->next){
            if(guard == cursor->next->val){
				temp = cursor->next;
                cursor->next = cursor->next->next;
				delete temp;
            }else{
                guard = cursor->next->val;
                cursor = cursor->next;
            }
        }
        return head;
    }
};
