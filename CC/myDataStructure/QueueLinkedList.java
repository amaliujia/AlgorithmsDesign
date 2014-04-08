/*
 * Queue implementation with linked list
*/
public class LinkedQueue<T>
{
	private class Node
	{
		private T data;
		private Node next;
		public Node()
		{
			next = null;
			data  = null;
		}
		public Node(T data, Node next)
		{
			this.data = data;
			this.next = next;
		}
	}
	
	private Node front;
	private Node rear;
	private int size;
	
	public LinkedQueue()
	{
		front = null;
		rear = null;
		size = 0;
	}
		
	public LinkedQueue(T element)
	{
		front  = new Node(element, null);
		rear = front;
		size++;
	} 
	
	public int length()
	{
		return size;
	}

	public void insert(T element)
	{
		if(front == null)
		{
			front = new Node(element, null);
			rear = front;	
		}else{
			new aNode = new Node(element, null);
			rear.next = aNode;
			rear = aNode;
		}
		size++;
	}
		
	public T remove()
	{
		Node old = front;
		front = front.next;
		old.next = null;
		size--;
		return old.data; 
	}

	public T element()
	{
		return front.data;
	}

	public boolean empty()
	{
		return size == 0;
	}

	public void clear()
	{
		front = null;
		rear = null;
		size = 0; 
	}

	public String toString()
	{
		if(empty())
		{
			return "[]";
		}else{
			StringBuffer buffer = new StringBuffer();
			Node iterator = front;
			buffer.append("[");
			while(iterator.next != null)
			{
				buffer.append(iterator.data);
				buffer.append(", ");
				iterator = iterator.next;
			}
			buffer.append(iterator.data);
			buffer.append("]"		    	
			return buffer.toString();
		}
	}
}
