public boolean[] listOfPrimes(int max){
	boolean[] pri = new boolean[max+1];
	
	pri[0] = pri[1] = false;
	for(int i = 2; i <= max; i++) pri[i] = true;

	int prime = 2;
	while(prime < Math.sqrt(max)){
		crossOff(pri, prime);
		prime = getNextPrime(pri, prime);
		
		if(prime >= pri.length()){
			break;
		}
	}
	return pri;
}

public void crossOff(boolean[] list, int prime){
	for(int i = prime * prime; i < list.length(); i = prime * i)
		list[i] = false;
}

public int getNextPrime(boolean[] list, int prime){
	for(int i = prime + 1; i < list.length(); i++){
		if(list[i] != false)	return i;
	}	
}
