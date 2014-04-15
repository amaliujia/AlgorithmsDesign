/*
	digits stored in forward order in linked list
*/

public static LinkedListNode(LinkedListNode a, LinkedListNode b)
{
	LinkedListNode head = new LinkedListNode();
	LinkedListNode master = null;
	LinkedListNode slave = null;
	
	if((a.data + b.data) <=  9){
		head.data = 9;
		slave = head;
	}else{
		head.data = 1;
		slave = new LinkedListNode();
		slave.data = (a.data + b.data) % 10;
		head.next = slave; 
	}
	a = a.next;
	b = b.next;
	
	while(a != null){
		if((a.data + b.data) > 9){
				master = new LinkedListNode();
				master.data = (a.data + b.data) % 10;
				slave.data += 1;
				slave.next = master;
				master = master.next; 
		}else{
                master = new LinkedListNode();
                master.data = a.data + b.data;
                slave.next = master;
                master = master.next;
		}
	}
	return head;
}
