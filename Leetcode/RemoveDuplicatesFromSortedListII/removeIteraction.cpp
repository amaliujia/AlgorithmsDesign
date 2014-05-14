class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode *saver = dummy;
    ListNode *cur = head;
    
    
    while( cur != NULL ){
        bool duplicated = false;
        while((cur!= NULL) && (cur->next != NULL) && (cur->val == cur->next->val)){
            duplicated = true;
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
        }
        if(duplicated == true){
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
            continue;
        }
        saver->next = cur;
        saver = saver->next;
        cur = cur->next;
    }
    saver->next = cur;
    return dummy->next;
}
};
