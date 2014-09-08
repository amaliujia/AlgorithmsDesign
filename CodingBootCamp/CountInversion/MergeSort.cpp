// O(nlogn)

int countInversion(int a[], int n){
	int *temp = new int[n]; 
	return mergeSort(a, temp, 0, n - 1);
}

int mergeSort(int a[], int temp[], int left, int right){
	if(left >= right)	return;
	int mid = left + (right - left) / 2;
	int count = 0; 
	count += mergeSort(a, temp, left, mid);
	count += mergeSort(a, temp, mid + 1, right); 
	count += merge(a, temp, left, right, mid);
	return count;
}


int merge(int a[], int temp[], int left, int right, int mid){
	int i, j;
	int count = 0;
	i = left;
	j = mid + 1;	
	int curr = 0;	
	while(i <= mid && j <= right){
		if(a[i] <= a[j]){
			temp[curr++] = a[i++];
		}else{
			count += (mid - i + 1);
			temp[curr++] = a[j++];	
		}	
	}
	while(i <= mid)	temp[curr++] = a[i++];
	while(j <= right)	temp[curr++] = a[j++];
	curr = left;
	for(i = 0; i < (right - left + 1); i++){
		a[curr++] = temp[i];
	} 

	return count;	
} 
