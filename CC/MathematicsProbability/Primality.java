public boolean navie(int n){
	if(n < 2) return false;

	for(int i = 2; i < n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

public boolean smart(int n){
	if(n < 2) return false;
	
	int sqrt = (int)Math.sqrt(n);

	for(int i = 0; i <= sqrt; i++){
		if(n % i == 0) return false;
	}
	return true;
}
