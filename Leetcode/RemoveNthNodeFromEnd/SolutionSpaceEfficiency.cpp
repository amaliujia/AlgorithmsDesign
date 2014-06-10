// O(n) time
// O(1) space

ListNode *removeNthFromEnd(ListNode *head, int n){
	ListNode dummy{-1, head};
	ListNode *p = &dummy;
	ListNOde *q = p;

	for(int i = 0; i < n; i++){
		p = p->next;
	}

	while(p->next != NULL){
		p = p->next;
		q = q->next;
	}

	ListNode *temp = q->next;
	q->next = q->next->next;
	delete temp;
	return dummy.next;
}
