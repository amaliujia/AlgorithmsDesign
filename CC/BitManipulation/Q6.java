public int swapBits(int target){
	int a = target << 1;
	int b = target >> 1;
	//a = a & 101010101010101010101010101010;
	a = a & 0xaaaaaaaa;
	//b = b & 010101010101010101010101010101;
	b = b & 0x55555555;
	return a | b;
}
