public int magicBit(int[] arr, int left, int right){
	int middle = (left + right) / 2;
	
	if(left > right | right >= arr.length | left < 0) return -1;	
	
	if(middle = arr[middle])				return middle;

	// search left
	int leftIndex = Math.min(middle-1, arr[middle]);
	int left = magicBit(arr, left, leftIndex);
	if(left >= 0)	return left	

	// search right
	int rightIndex = Math.max(middle+1, arr[middle]);
	int right = magicBit(arr, rightIndex, right);
	return right;
}

