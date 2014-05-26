public int runupStair(int n){
	return recurRun(n);
}

public int recurRun(int n){
	if(n < 0) return 0;
	if(n == 0) return 1;
	return  recurRun(n-1) + recurRun(n-2) + recurRun(n-3);
}
