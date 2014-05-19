public int bitRequiredByInt(int a, int b){
	int c = a ^ b;
	int count = 0;
	for(c; c != 0; c = c & (c - 1)){
		count++;
	}
	return count;
}
