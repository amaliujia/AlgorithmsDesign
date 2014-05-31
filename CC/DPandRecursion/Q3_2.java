public int magicBit(int[] arr){
    return getBit(arr, 0, arr.length()-1);
}

public int getBit(int[] arr, int l, int r){
	int temp = (l + r) / 2;

	if(i > r) 					return -1;
	if(arr[temp] == temp)		return temp;

	if(temp > arr[temp])		return getBit(arr, temp+1, r);
	if(temp < arr[temp])		return getBit(arr, l, temp+1); 
i}
