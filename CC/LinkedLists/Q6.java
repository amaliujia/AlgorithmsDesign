public static LinkedListNode(LinkedListNode head)
{
	LinkedListNode master = null;
	LinkedListNode slave = null;
	master = head;
	slave = head;
	while(master != null && master.next != null){
		master = master.next.next;
		slave = slave.next;
		if(master == slave){
			break;
		}
	}

	// there isn't any loop here.
	if(master == null || master.next == null) return null;

	slave  = head;
	while(master != slave){
		master = master.next;
		slave = slave.next;
	}
	return slave;
}
