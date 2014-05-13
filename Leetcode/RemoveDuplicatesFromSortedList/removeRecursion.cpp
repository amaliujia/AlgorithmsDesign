class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		if(!head) return head;

		ListNode dummy(head->val+1);
		dummy.next = head;

		recursionDelete(&dummy, head);
		return dummy.next;
	}

private:
	static void recursionDelete(ListNode *prev, ListNode *cur){
		if(cur == NULL) return;

		if(pre->val == cur->val){
			pre->next = cur->next;
			delete cur;i
			recursionDelete(pre, pre->next);
		}else{
			recursionDelete(pre->next, cur->next);
		}
	}
};
