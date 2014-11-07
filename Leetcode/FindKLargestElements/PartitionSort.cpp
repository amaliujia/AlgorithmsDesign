int partition(int a[], int low, int high){
	int i, j, pivot;
	pivot = a[i];
	i = low;
	j = high;
	
	while(i < j){
		while(a[j] < index && i < j)	j--;
		if(i < j){
			a[i] = a[j];
			i++;
		}	
		while(a[i] >= index && i < j)	i++;
		if(i < j){
			a[j] = a[i];
			j--;
		}
	}
	a[i] = index;
	return i;	
}

int kBigElement(int a[], int low, int high, int k){
	int par = partition(a, low, high);
	int dis = high - par + 1;
	if(dis == k)	return par;
	else if(dis > k)	return kBigElement(a, par + 1, high, k);
	else	return kBigElement(a, low, par - 1, k - dis);	
}
