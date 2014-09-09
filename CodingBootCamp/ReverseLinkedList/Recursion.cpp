Node *reverseLinkedList(Node *head){
	if(head == NULL || head->next == NULL)	return head;
		
	Node *p = reverseLinkedList(head->next);
	
	head->next->next = head;
	head->next = NULL;	
	return p;	
}
