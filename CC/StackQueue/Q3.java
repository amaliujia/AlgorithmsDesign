/*
    set of stacks
*/

public class StackSet<T>{
    public int _capacity;
    public int _default_capacity = 100;
    Deque<T> buffer;
    ArrayList<Deque<T>> stackList = new ArrayList<Deque<T>>();
    public StackSet(int capacity ){
        buffer = new ArrayDeque<T>();
        _capacity = capacity;
        stackList.add(buffer);
    }
    public StackSet(){
        buffer = new ArrayDeque<T>();
        _capacity = _default_capacity;
        stackList.add(buffer);
    }
    
    public void push(T element){
    	if(buffer.size() >  _capacity){
    		stackList.add(buffer);
    		buffer = new ArrayDeque<T>();
    		buffer.addLast(element);
    	}else{
    		buffer.addLast(element);
    	}	
    }
    
    public T pop() throws Exception{
    	T result = null;
    	if(stackList.size() >= 2 && buffer.size() == 1){
    		result = buffer.pollLast();
    		stackList.remove(stackList.size() - 1);
    		buffer = stackList.get(stackList.size() - 1);
    	}else if(isEmpty()){
    		throw new Exception("no element to pop");
    	}else{
    		result = buffer.pollLast();
    	}
		return result;
    }
   
    public T popAt(int index) throws Exception{
    	if(stackList.size() < index) throw new Exception("IndexOutOfRange!");
    	else return stackList.get(index - 1).pollLast();
    }
 
    public T peek(){
    	return buffer.peek();
    }
    
    public boolean isEmpty(){
    	if(stackList.size() == 1 && buffer.size() == 0){
    		return true;
    	}
    	return false;
    }
}
