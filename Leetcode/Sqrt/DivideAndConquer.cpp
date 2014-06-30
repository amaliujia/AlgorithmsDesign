int sqrt(int x){
	if(x < 2) return x;
	
	int left = 1, right = x / 2;
	int recent_mid;

	while(left <= right){
		int mid = (left + right) / 2;
		if(x / mid > mid){
			left = mid + 1;
			recent_mid = mid;
		}else if(x / mid < mid){
			right = mid - 1;
		}else{
			return mid;
		}
	}
	return recent_mid;
}
