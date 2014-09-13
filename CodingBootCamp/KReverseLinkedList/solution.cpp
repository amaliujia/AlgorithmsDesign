
Node *kReverse(Node *head, int k){
	if(head == NULL || head->next == NULL)	return head;

	Node *prev = NULL;
	Node *curr = head;
	Node *temp;

	int count = 0;
	while(cout < k && curr != NULL){
		temp = curr->next;
		curr->next = prev;	
		prev = curr;
		curr = temp;
		k++;
	}

	head->next = kReverse(curr, k);
	return prev;
}
