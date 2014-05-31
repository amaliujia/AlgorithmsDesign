public int magicBit(int[] arr){
	int len = arr.length();
	getBit(arr, len-1);
}

public int getBit(int[] arr, int i){
	if(i < 0) 			return -1;
	if(i == arr[i]) 	return i;

	return getBit(arr, i-1); 
} 
