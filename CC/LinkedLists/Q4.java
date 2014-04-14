/*
	partition linkedList by a value. O(n) time
*/

public LinkedListNode  partitionLinkedList(LinkedListNode head, int x)
{
	LinkedListNode firstOne = null;
	LinkedListNode firstEnd = null;
	LinkedListNode secondOne = null;
	LinkedListNode secondEnd = null;
	LinkedListNdoe master = head;
	while(master != null){
		LinkedListNode next = master.next;
		master.next = null;
		if(master.data < x){
			if(firstOne == null){
				firstEnd = master;
				firstOne = firstEnd;
			}else{
				firstEnd.next = master;
				firstEnd = firstEnd.next;
			}
		}else{
			if(secondOne == null){
				secondOne = master;
				secondEnd = secondOne;
			}else{
				secondEnd.next = master;
				secondEnd = secondEnd.next;
			}
		}
		master = next;
	}
		
	if(secondOne == null)	return firstOne;
    if(firstOne == null) return secondOne;	
	firstEnd.next = secondOne;
	return firstOne;
}
