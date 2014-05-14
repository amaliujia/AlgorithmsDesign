/*
	tricks

	x ^ 0s = x				x ^ 1s = ~x				x ^ x = 0
	x & 0s = 0				x & 1s = x				x & x = x
	x | 0s = x				x | 1s = 1s				x | x = x
*/
boolean getBit(int num, int i){
	return num & (1 << i);
}

boolean setBit(int num, int i){
	return num | (1 << i);
}

int clearBit(int num, int i){
	return num & (~(1 << i));
}

int clearBitsMSBThroughI(int num, int i){
	return num & ((1 << i ) - 1);
}

int clearBitsIthrough0(int num, int i){
	return num & ~(1 << (i+1) - 1);
}

int updateBit(int num, int i, int v){
	return num & ~(1 << i) | (v << i);
}
