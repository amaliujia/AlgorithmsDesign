/*
	Naive (O(N^2) time), but space efficient(O(1))
*/
void removeDuplicate(Node head)
{
	if(head == null) return;
	Node current = head;
	while(current != null){
		Node runner = current;
		while(runner.next != null){
			if(runner.next.data == current.data){
				runner.next = runner.next.next;
			}else{
				runner = runner.next;
			}
		}
		current = current.next;
	}
}
