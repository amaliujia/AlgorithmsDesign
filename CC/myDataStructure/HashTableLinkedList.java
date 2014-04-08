public class HashTable {
	private int capacity;
	private Node[] nodes;
	
	public HashTable()
	{
		this.capacity = 1000;
		nodes = new Node[this.capacity];
		for(Node n:nodes)
		{
			n = null;
		}
	}
	public HashTable(int ca)
	{
		this.capacity = ca;
		nodes = new Node[this.capacity];
		for(Node n:nodes)
		{
			n = null;
		}
	}
	
	public int put(Object key, Object value)
	{
		
		int hashcode = key.hashCode() % capacity;
		Node currentNode = new Node();
		currentNode.key = key;
		currentNode.value = value;
		if(nodes[hashcode] == null)
		{
			nodes[hashcode] = currentNode;
		}else{
			if(nodes[hashcode].key.equals(key) == true)
			{
				nodes[hashcode].value = value;
			}else{
				currentNode.next = nodes[hashcode];
				nodes[hashcode] = currentNode;
			}
		}
		return hashcode;
	}
	public Node get(Object key)
	{
		int hashcode = key.hashCode();
		Node node = new Node();
		node = nodes[hashcode];
		while(node != null && node.next != null)
		{
			if(node.key.equals(key))
			{
				return node;
			}
		}
		return null;
	}
	private class Node{
		private Object key;
		private Object value;
		private Node next;
		
		public Node()
		{
			key = null;
			value = null;
			next = null;
		}
	}
	
}
