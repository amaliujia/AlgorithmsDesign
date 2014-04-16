/*
	every state of this stack have a minimum number, even when it's empty(this max infinity). Therefore the solution is to use a extra stack to store those minimums, and change this stack based on the changes of main stack.
*/

public class stackWithMin extends Stack<Integer>{
	public Stack<Integer> minStack;
	public stackWithMin(){
		minStack = new Stack<Integer>();
	}

	public void push(int value){
		if(value < min()){
			minStack.push(value);
		}

		super.push(value);
	}

	public Integer pop(){
		int v = super.pop();
		if(v == min()) minStack.pop();
		return v;
	}

	public int min(){
		if(minStack.isEmpty()){
			return Integer.MAX_VALUE;
		}else{
			return minStack.peek();
		}
	}
}
