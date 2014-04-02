class Solution{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		unsigned long long sum = 0;
		ListNode *head = NULL;
		ListNode *tail = NULL;
		while(l1 != NULL || l2 != NULL)
		{
			if(l1 != NULL){
				sum += l1->val;
				l1 = l1->next;
			}
			if(l2 != NULL){
				sum += l2->val;
				l2 = l2->next;
			}
			if(head == NULL)
			{
				head = new ListNode(sum%10);
				tail = head;
			}else{
				tail->next = new ListNode(sum%10);
				tail = tail->next;
			}		
			sum /= 10;
		}
		if(sum != 0)
		{
            tail->next = new ListNode(sum%10);
            tail = tail->next;
		}
		return head;
	}
}
