int minHeap(int a[], int index, int k){
	int minIndex = index;
	int leftIndex = index * 2;
	int rightIndex = index * 2 + 1;

	if(leftIndex < k && a[leftIndex] < a[minIndex]){
		minIndex = leftIndex;				
	}  
	
	if(rightIndex < k && a[rightIndex] < a[minIndex]){
		minIndex = rightIndex;
	}

	if(minIndex != index){
		int temp = a[minIndex];
		a[minIndex] = a[index];
		a[index] = temp;
		minHeap(a, minIndex, k);	
	} 	
	return 0;		
}

