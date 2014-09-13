// Binary searchm so this O(logn)
int sqrt(int n, int abs){
	int left = 0;
	int right = (n >= 1) ? n : 1;
	while(left + abs < right){
		int middle = left + (right - left) / 2;
		if(n / middle == middle)    return middle;
		else if(n / middle <  middle)	right = middle;
		else	left = middle;	
	}
	return left;
}
