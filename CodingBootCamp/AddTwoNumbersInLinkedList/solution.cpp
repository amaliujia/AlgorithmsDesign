struct Node{
  int data;
  Node *next;
};

Node *newNode(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

Node *addNumbers(Node *n1, Node *n2){
	if(n1 == NULL)	return n2;
	if(n2 == NULL)	return n1;

	Node *head = NULL;
	Node *temp, prev;
	int carry = 0, sum;	
	while(n1 != NULL || n2 != NULL){
		sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
		carry = sum / 10;
		temp = newnode(sum % 10);
		
		if(head == NULL)	head = temp;
		else prev->next = temp;
		
		prev = temp;

		if(n1) n1 = n1->next;
		if(n2) n2 = n2->next;	
	}
	if(carry)	prev->next = newnode(carry);				
	return head;
}	
