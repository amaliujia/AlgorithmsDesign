/*
	flexible space of stacks in array.
	pretty complicated.
	The basic idea is to put these stacks one by one from the beginning of array. Once we need to push elements, we try to shift other stacks for more room.
*/
public class StackData{
	public int start;
	public int pointer;
	public int size = 0;
	public int capacity;
	public StackData(int aStart, int aCapacity){
		start = aStart;
		pointer = aStart - 1;
		capacity = aCapacity;
	}

	public boolean isWithinStack(int index, int total_size){
		if(start <= index && index < start + capacity){
			return true;	
		}else if(start + capacity > total_size && index < (start + capacity) % total_size){
			return true;
		}	
	return false;
	}
}

public class QuestionB{
	static int number_of_stacks = 3;
	static int defalue_size = 4;
	static int total_size = default_size * number_of_stacks;
	static StackData[] stacks = {new StackData(0, default_size), new StackData(default_size, default_size), new StackData(default_size * 2, default_size)};
	static int[] buffer = new int[total_size];

	public static void main(String[] args) throws Exception{
		push(0, 10);
		push(1, 20);
		push(2, 30);
		pop(0);
	}
}

public static int numberOfElements(){
	return stacks[0].size + stacks[1].size + stacks[2].size;
}

public static int nextElement(int index){
	if(index + 1 == total_size) return 0;
	else return index + 1;
}

public static int previouselement(int index){
	if(index == 0) return total_size - 1;
	else return index - 1;
}

public static void shift(int stackNo){
	StackData stack = stacks[stackNo];
	if(stack.size >= stack.capacity){
		int nextStack = (stackNo + 1) % number_of_stacks;
		shift(nextStack); //make some room
		stack.capacity++;
	}
	//shift elements in reverse order
	for(int i = (stack.start + stack.capacity - 1) % total_size; stack.isWithinstack(i, total_size); i = previousElement(i)){
		buffer[i] = buffer[previousElement(i)];
	}

	buffer[stack.start] = 0;
	stack.start = nextElement(stack.start); // move start
	stack.pointer = nextElement(stack.pointer); // move top
	stack.capacity--;
}

public static void expand(int stackNum){
	shift((stackNum+1)%number_of_stacks);
	stacks[stackNum].capacity++;	
}

public static void push(int stackNum, int value) throws Exception{
	StackData stack = stacks[stackNum];
	//check if there are enough space
	if(stack.size >= stack.capacity){
		if(numberOfElements() >= total_size) throw new Exception("Out of space");
		else // try to dynamically expand space 
			expand(stackNum);
	}

	stack.size++;
	stack.point = nextElement(stack.pointer);
	buffer[stack.pointer] = value;
}

public static int pop(int stackNum) throws Exception{
	StackData stack = stacks[stackNum];
	if(stack.size == 0){
		throw new Exception("Trying to pop an empty stack.");
	}
	int value = buffer[stack.pointer];
	stack.pointer = previousElement(stack.pointer);
	stack.size--;
	return value;
}

public static int peek(int stackNum){
	StackData stack = stacks[stackNum];
	return buffer[stack.pointer];
}

public static boolean isEmpty(int stackNum){
	StackData stack = stacks[stackNum];
	return stack.size == 0;
}
