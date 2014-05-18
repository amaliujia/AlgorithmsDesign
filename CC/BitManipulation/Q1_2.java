public int changeBits(int source, int stuff, int end, int start){
	int all = ~0;
	int left = all << (end + 1);
	int right = 1 << i - 1;
	int mask = left | right;

    int inter = source & mask;

    return inter | stuff;
}
