//O(n) time

int findPeek(int a[], int n){
	int left = 0, right = n - 1;
	int mid = (left + right) / 2;
	
	while(left <= right){
		if((mid == 0 || a[mid] > a[mid - 1]) &&
		   (mid == n - 1 || a[mid] > a[mid + 1])){
			return a[mid];
		}else if((mid - 1 >= 0) && (a[mid] < a[mid - 1])){
			right = mid - 1;	
		}else if(mid + 1 <= 0 && a[mid] < a[mid + 1]){
			left = mid + 1;
		}else{
			return	INT_MIN; 
		}
	}
	return INT_MIN;	
}

