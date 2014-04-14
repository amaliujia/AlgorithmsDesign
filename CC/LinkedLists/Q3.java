public boolean deleteMiddleNode(LinkedListNode node)
{
	if(node == null){
		return false;
	}
	if(node.next == null){
		node = null;
		return true;
	}
	node.data = node.next.data;
	node.next = node.next.next;
	return true;
}
