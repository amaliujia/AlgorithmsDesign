int missingInteger(int a[], int length){
	int sum = 0;
	for(int i = 0; i < length; i++){
		sum += a[i];
	}
	return length * (length + 1) / 2 - sum;
}
