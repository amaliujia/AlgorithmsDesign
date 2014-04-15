/*
class Node{
	int data;
	Node* next;
	Node(int x):data(x), next(NULL){}
};
*/

Node* addNumbersInLinkedList(Node* a, Node* b)
{
	int intermedia  = 0;
	Node* head = NULL;
	Node* n = NULL;
	while(a != NULL){
		if(head == NULL){
			head = new Node((a->data + b->data + intermedia) % 10);
			n = head;
		}else{
			n->next = new Node((a->data + b->data + intermedia) % 10);
			n = n->next;
		}
        intermedia = (a->data + b->data + intermedia) / 10;
		a = a->next;
		b = b->next;
	}
	return head;
}
