Node *reverseLinkedList(Node *head){
	if(head == NULL || head->next == NULL)	return head;
	
	Node *cur = head;
	Node *prev = NULL;
	Node *temp;
	
	while(cur != NULL){
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;		
	}
	return prev;
}

