/*
	O(n) time
	O(n) space
*/
ListNode *reverseKGroup(ListNode *head, int k){
	if(head == NULL || head->next == NULL || k < 2){
		return head;
	}

	ListNode *pn = head;
	for(int i = 0; i < k; i++){
		if(pn->next) pn = pn->next;
		else	return head; 
	}
	
	ListNode *newGouphead = reverseKGroup(pn, k);

	ListNode *prev = NULL, *curr = head;

	while(curr != pn){
		ListNode *next = curr->next;
		curr->next = prev ? prev : newGrouphead;
		prev = curr;
		curr = next;
	}
	return prev;			
}
