public class intTank{
	public int value = 0;
}

public Node nthToLast(Node head, int k, intTank i)
{
	if(head == null) return null;
	
	Node n = nthToLast(head.next, k, i);

	if(i.value == k) return head;

	return n;
}
