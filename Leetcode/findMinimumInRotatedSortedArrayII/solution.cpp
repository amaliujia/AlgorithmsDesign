int findMin(vector<int> &num) {
	if(num.size() == 1)	return num[0];	        
	
	return findMinRecursion(num, 0, num.size() - 1);    
}

int findMinRecursion(vector<int> &num, int low, int high){
	if(low > high){
		return num[0];
	}
	if(low == high){
		return num[low];
	}
	
	int mid = low + (high - low) / 2;

	if(mid < high && arr[mid + 1] < arr[mid]){
		return arr[mid + 1];
	}

	if(arr[low] == arr[midd] && arr[high] == arr[mid]){
		return min(findMinRecursion(arr, low, mid - 1), 
				   findMinRecursion(arr, mid + 1, high));
	}
	
	if(mid > low && arr[mid] < arr[mid - 1]){
		return arr[mid];
	}

	if(arr[high] >= arr[mid])
		return findMinRecursion(arr, low, mid - 1);
	return findMinRecursion(arr, mid + 1, high);		
}
