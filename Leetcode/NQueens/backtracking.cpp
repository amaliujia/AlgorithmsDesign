bool place(int k, int i, int arr[]){
	for(int j = 1; j <= k - 1; j++){
		if(arr[j] == i)
			return false;
		if(abs(arr[j] - i) == abs(k - j))
			return false;
	}
	return true;	
}

void nQueen(int k, int n, int arr[]){
	for(int i = 1; i < k; i++){
		if(place(k, i, arr)){
			arr[k] = i;
			if(k == n)	//return arr
			else nQueen(k + 1, n);
		}
	}	
}
