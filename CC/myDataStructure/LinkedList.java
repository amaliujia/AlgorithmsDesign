class Node{
	Node next = null;
	int data;

	Node(int a){
		data = a;
	}
	
	void appendToTail(int d){
		Node end = new Node(d);
		Node n = this;
		while(n.next != null){
			n = n.next;
		}
		n.next = end;
	}

	Node deleteNode(Node head, int d){
		Node n = head;
		if(n.data == d){
			return head.next;
		}
	
		while(n.next != null){
			if(n.next == d){
				n.next = n.next.next;
				return head;
			}
			n = n.next;
		}
		return head;
	}
}
