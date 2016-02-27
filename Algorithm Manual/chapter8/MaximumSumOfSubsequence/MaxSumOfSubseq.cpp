int MaxSumSubseq(char *s)
{
	int length = strlen(s);
	int maxSum = -INF;;
	int sum = 0;
	for(int i = 0; i < length; i++)
	{
		if(sum < 0)
		{
			sum = s[i];
		}else{
			sum += s[i];
		}	

		if(sum > maxSum)
		{
			maxSum = sum;
		}
	}
	return maxSum;
}
