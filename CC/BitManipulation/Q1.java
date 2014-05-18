public int changeBits(int source, int stuff, int end, int start){
	int intermediate = source;
	for(int i = start; i <= end; i++){
		intermediate = setBit(source, i); 
	}

	stuff = stuff << start;
	
	return intermediate | stuff;	
}

public int setBit(int source, int i){
	return source & (~(1 << i));
}
