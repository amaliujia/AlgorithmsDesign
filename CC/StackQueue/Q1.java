/*
	stacks with a fixed amount of space.
*/

int stackSize = 100;
int[] buffer = new int[stackSize * 3];
int[] stackPointer = {-1, -1, -1}; //pointers tracking the top of stack

void push(int stackNo, int value) throws Exception{
	if(stackPointer[stackNo] + 1 >= stackSize){
		throw new Exception("out of space!");
	}
	stackPointer[stackNo]++;
	buffer[stackSize * stackNo + stackPointer[stackNo]] = value;
}

int pop(int stackNo) throws Exception{
	if(stackPointer[stackNo] == -1){
		throw new Exception("no available element to pop!");
	}
	stackPointer[stackNo]--;
	return buffer[stackSize * stackNo + stackPointer[stackNo] + 1];
}

int top(int stackNo){
	return buffer[stackSize * stackNo + stackPointer[stackNo]];
}

boolean isEmpty(int stackNo){
	return stackPointer[stackNo] == -1;
}
