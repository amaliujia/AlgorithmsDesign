// O(n) time
void kSmallest(int a[], int left, int right, int n, int k){
	if(k > n)	return;
	
	//int mid = left + (right - left) / 2;	
	int pivot = a[left];
	int i = left, j = right;
	while(i < j){
		//while(a[i] < pivot)	i++;
		while(i < j && a[j] >= pivot)	j--;
		if(i < j){
			a[i] = a[j];
			i++;
		}
		while(i < j && a[i] <= pivot)   i++;
		if(i < j){
			a[j] = a[i];
			j--;	
		}		
	}
	a[i] = pivot; 	
	if((i - left + 1) == k)	return;
	else if((mid - left + 1) > k)	kSmallest(a, left, i, n, k);
	else	kSmallest(a, i + 1, right, n, k - (mid - left + 1));
	return; 
}

void solution(int a[], int n, int k){
	kSmallest(a, 0, n - 1, n, k);
} 
