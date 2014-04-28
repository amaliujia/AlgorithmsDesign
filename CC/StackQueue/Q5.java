Class MyQueue{
	private Stack s1;
	private Stack s2;

	public MyQueue(){
		s1 = new Stack();
		s2 = new Stack();
	}

	public void insert(int data){
		while(s2.top()){
			s1.push(s2.pop());
		}
		s2.push(data);
	}

	public int remove() throw Exception{
		if(isEmpty()){
			throw new Exception("Queue is empty");
		}
		while(s1.top()){
            s2.push(s1.pop());
        }
        return s2.pop();
	}

	public boolean isEmpty(){
		if(s1.top() || s2.top())
			return false;
		return true;
	}

	public int length(){
		if(isEmpty()) return 0;
		int count = 0;
		while(s1.top()){
            s2.push(s1.pop());
        }
		while(s2.top()){
			s1.push(s2.pop());
			count++;
		}
		return count;
	}
}
