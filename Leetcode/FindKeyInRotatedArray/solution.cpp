bool findKey(int a[],int low, int high, int key){
	int middle = (hight - low) / 2 + low;
	
	if(a[middle] == key)	return 	true;
	else if(a[middle] < key){
		if(a[middle] < a[low]){
			return findKey(a, low, middle - 1, key);
		}else{
			return findKey(a, middle + 1, high, key);
		}
	}else{
		if(a[middle] > a[high]){
			return findKey(a, middle + 1, high, key); 
		}else{
			return findKey(a, low, middle - 1, key);
		}
	}	
}
