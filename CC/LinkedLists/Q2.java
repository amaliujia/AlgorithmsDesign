Node kthToLast(Node head, int k)
{
	int flag = 1;
	Node master = head;
	Node slave = head;

	while(flag <  k){
		master = master.next;
		flag++;
	}
	
	while(master.next != null){
		master = master.next;
		slave = salve.next;
	}
	return slave;
}
