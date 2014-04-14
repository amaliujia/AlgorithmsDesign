/*
	usually each recursive step need O(1) space, then totally space O(n)
*/
public static int countToEnd(Node head, int k)
{
	if(head == null) return 0;
	
	int i = countToEnd(head.next, k) + 1;
		
	if(i == k)	System.out.println("catch it!!");
}
