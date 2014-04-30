/*
 * Queue implementation with array
*/

public class SequenceQueue<T>
{
	private capacity;
	private int DEFALUT_SIZE = 10;
	private Object[] elementData;
	private int front = 0;
	private int rear = 0;

	//default constructor usning Object array with default size
	public SequenceQueue()
	{
		capacity = DEFALUT_SIZE;
		elementData = new Object[capacity];
	}

	//constructor with first element of queue
	public SequenceQueue(T element)
	{
		//call default constructor by this()
		this();
		elementData[0] = element;
		rear++;
	}

	/**
	 * create queue with given capacity 
	 * @param element first element of queue
	 * @param capacity the capacity of array
	**/
	public SequenceQueue(T element, int capacity)
	{
		this.capacity = capacity;
		elementData = new Object[this.capacity];
		elementData[0] = element;
		rear++;
	}

	// get the length of queue
	public int length()
	{
		if(Empty())
		{
			return 0;
		}
		return rear > front ? rear - front : capacity - (front - rear);
	}

	// insert a element into queue
	public void insert(T element)
	{
		if(rear > capacity - 1)
		{
			rear = 0;
		}
       if(front > capacity - 1)
        {
            front = 0;
        }
	    if(rear == front - 1)
		{
			throw new IndexOutOfBoundsException("Queue is full");
		}	
		elementData[rear++] = element;
	}	
	
	// remove a element from queue
	public T remove()
	{
		if(empty())
		{
			throw new IndexOutOfBoundsException("Empty queue exception");
		}
		T target = (T)elementData[front];
		elementData[front++] == null;
		return target;
	}

	// if queue is empty
	public boolean empty()
	{
		return (rear == front) && (elementData[rear] == null);	
	}
	
	// return element in front, but not delete it
	public T element()
	{
		if(empty())
        {
            throw new IndexOutOfBoundsException("Empty queue exception");
        }
		return (T)elementData[front];
	}

	// clear the queue	
	public void clear()
	{
		Arrays.fill(elementData, null);
		front = 0;
		rear = 0;
	}	

	public String toString()
	{
		if(empty())
		{
			return "[]";
		}else{
			StringBuffer str = new StringBuffer();
			str.append("[");
			if(rear > front){
				for(int i = front; i < rear - 1; i++)
				{
					str.append(elementData[i].toString());
					str.append(", ");
				}
				str.append(elementData[rear-1].toString());
				str.append("]");
				return str.toString();
			}else{
				for(int i = front; i < capacity; i++)
				{
                    str.append(elementData[i].toString());
                    str.append(", ");
				}
				for( int i = 0; i < rear - 1; i++)
				{
                    str.append(elementData[i].toString());
                    str.append(", ");
				}
                str.append(elementData[rear-1].toString()); 
                str.append("]");
                return str.toString();				
			}
		}
	}
}
