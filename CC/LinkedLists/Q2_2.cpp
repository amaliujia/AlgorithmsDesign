Node* nthToLast(Node* head, int k, int& i)
{
	if(head == NULL) return NULL;
	
	Node* n = nthToLast(head->next, k, i);

	i = i + 1;
	
	if(i == k)	return head;

	return n;
}
