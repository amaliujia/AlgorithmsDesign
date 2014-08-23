// O(n) time;
// O(1) space
RandomListNode *copyRandomList(RandomListNode *head){
	RandomListNode *cur = head;
	while(cur != NULL){
		RandomListNode *p = new RandomListNode(cur->label);
		p->next = cur->next;
		cur->next = p;
		cur = p->next;
	}

	cur = head;
	while(cur != NULL){
		RandomListNode *p = cur->next;
		if(cur->random != NULL){
			p->random = cur->random->next;	
		}	
		cur = p->next;
	}

	cur = head;
	RandomListNode *headCopy = head == NULL ? NULL: head->next;
	while(cur != NULL){
		RandomListNode *p = cur->next;
		cur->next = p->next;
		if(p->next != NULL){
			p->next = p->next->next;		
		}
		cur = cur->next;
	}
	return headCopy;
}
