bool canJump(int A[], int n){
	if(n == 0)	return true;
	
	int step = A[0];
	for(int i = 1; i < n; i++){
		if(step > 0){
			step--;
			step = max(step, A[i]);
		}else{
			return false;
		}
	}
	return true;
}
