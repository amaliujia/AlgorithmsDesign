// As a sort method, merge sort can promise O(nlogn) time

ListNode *sortList(ListNode *head){
	if(head == NULL)	return NULL;
	int len = 0;
	ListNode *it = head;
	while(it != NULL){
		it = it->next;
		len++;
	}
	it = sort(&head, len);
	return it;	
}

//divide and conquer
ListNode *sort(ListNode **head, int length){
	if(length == 1){
		ListNode *p = *head;
		*(head) = (*head)->next;
		p->next = NULL;
		return p;
	}
	ListNode *leftside = sort(head, length / 2);
	ListNode *rightside = sort(head, length - length / 2);
	ListNode *intermediate = merge(leftside, rightside);
	return intermediate;
}

//Linked list merge function
ListNode *merge(ListNode *left, ListNode *right){
	ListNode *dummy = new ListNode(-1);
	ListNode *curr = dummy;
	while(left != NULL && right != NULL){
		if(left->val < right ->val){
			curr->next = left;
			left = left->next;
		}else{
			curr->next = right;
			right = right->next;
		}
		curr = curr->next;	
	}
	if(left != NULL)	curr->next = left;
	if(right != NULL)	curr->next = right;		
	curr = dummy->next;
	delete dummy; 
	return curr;		
}
