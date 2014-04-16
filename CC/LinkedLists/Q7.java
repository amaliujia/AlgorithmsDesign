/*
	judege if a linked list is palindrome
	O(n) space
	O(n) time
*/

public static boolean LinkedListAndPalindrome(LinkedListNode head) 
{
	if(head == null) return false;
	if(head.next == null) return true;

	return recursiveSearch(head, head.next) == null ? false : true;
}

public static LinkedListNode recursiveSearch(LinkedListNode master, LinkedListNode slave){
	if(slave.next == null){
		if(master.data == slave.data){
			return master.next;
		}else{
			return null;
		}		
	}

	LinkedListNode n = recursiveSearch(master, slave.next);
	
	if(n == null) return null;

	if(master.data  == slave.data) return master.next;	
}

