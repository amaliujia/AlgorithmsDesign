public int negation(int b){
	int neg = 0;
	int t = b < 0 ? 1 : -1;

	while(b != 0){
		neg += t;
		b += t;
	}
	return neg;
}

public int abs(int a){
	if(a < 0)
		return negation(a);
	return a;
}
public int substract(int a, int b){
	return a + negation(b);
}

public int multiple(int a, int b){
	if(a < b) return multiple(b, a);

	int sum = 0;

	for(int i = abs(b); i > 0; i--)
		sum += a;

	if(b < 0)
		return negation(sum);
	return sum;
}

public int division(int a, int b){
	if(b == 0) return new Exception("divisor cannot be zero");

	int aa = abs(a);
	int ab = abs(b);
	int product = 0;
	int x = 0
	
	while(product + ab <= aa){
		product += ab;
		x++;
	}

	if((a<0 && b<0) || (a>0 && b>0)) return product;
	return negation(product);
}

	
