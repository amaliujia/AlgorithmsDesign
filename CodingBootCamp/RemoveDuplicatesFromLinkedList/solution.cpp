ListNode* removeDuplicatesFromLinkedList(ListNode* node){
	if(node == NULL || node->next == NULL)
		return node;

	ListNode dummy(-1);
    dummy.next = node;
	ListNode *slave = &dummy;
	 
	unordered_set<int> nodeSet;	
	while(slave->next != NULL){
		if(nodeSet.find(slave->next->val) == nodeSet.end()){
			nodeSet.put(slave->next->val);
		}else{
			ListNode *temp = slave->next;
			slave->next = slave->next->next;
			free(temp);
		}
	}
	return dummy.next;
}
