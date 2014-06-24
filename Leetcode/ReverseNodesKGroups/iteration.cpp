ListNode *reverseKGroup(ListNode *head, int k){
	if(head == NULL || head->next == NULL || k < 2){
		return head;
	}

	ListNode dummy(-1);
	dummy.next = head;

	for(ListNode *prev = &dummy, *end = head; end; end = prev->next){
		for(int i = 1; i < k && end; i++){
			end = end -> next;
		}
		if(end == NULL)	break;
		
		prev = reverse(prev, prev->next, end);
	}
}

ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end){
	ListNode *stop = end->next;
	for(ListNode *p = begin, *curr = p->next, *next = curr->next; curr != stop;
		p = curr, curr = next, next = next ? next->next : NULL){
		curr -> next = p;
	}

	begin->next = stop;
	prev ->next = end;
	return begin;
}
