/*
	Fabonacci Number by Dynamic Programming
*/

long Fabonacci(int n)
{
	int i = 0;
	long f1,f2,f3;
	f1 =0;
	f2 =1;
	if(n == 0)
	{
		return f1;
	}else if(n == 1){
		return f2;
	}else{
		while(i < n-1)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
			i++;
		}
	}
	return f3;
}
