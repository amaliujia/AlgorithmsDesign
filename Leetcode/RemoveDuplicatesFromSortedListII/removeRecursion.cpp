/*
	O(n) time
	O(1) space
*/
class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){

		return duplicates(head);	
	}
private:
	ListNode *duplicates(ListNode *head){
		if(!head || !(head->next)) return head;
		ListNode *p = head->next;
		if(head->val == p->val){
			ListNode *q = p->next;
			delete p;
			p = q;
			while(p && head->val == p->val){
				q = p->next;
				delete p;
				p = q;	
			}
			delete head;
			return duplicates(p);		
		}else{
			head->next = duplicates(head->next);
			return head;
		}	
	}
};
