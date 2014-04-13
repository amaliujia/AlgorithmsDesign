void removeDuplicates(Node head)
{
	boolean[] table = new boolean[256];
	Node n = head;

	table[n.data] = true;

	while(n.next != null){
		if(table[n.next.data] != true){
			table[n.next.data] = true;
			n = n.next;
		}else{
			n.next = n.next.next;
		}
	}
}
