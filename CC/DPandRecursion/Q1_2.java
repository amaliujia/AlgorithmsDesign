/*
	This time O(n) time, O(n) space
*/
public int runupStair(int n){
    int[] arr = new int[n];
	return recurRun(n, arr);
}

public int recurRun(int n, int[] arr){
    if(n < 0) return 0;
    if(n == 0) return 1;
   	if(arr[n] >= 0) return arr[n];
	else{ 
		arr[n] = recurRun(n-1) + recurRun(n-2) + recurRun(n-3);
		return arr[n];
	}
}
