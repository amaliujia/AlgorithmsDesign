int MaxSumSubseq(char *s)
{
	int length = strlen(s);
	int maxSum = -INF;
	int startM = 0, endM = 0;
	int sum = 0;
	int start = 0;

	for(int i = 0; i < length; i++)
	{
		if(sum < 0)
		{
			sum = s[i];
			start = i;
		}else{
			sum += s[i];
		}	

		if(sum > maxSum)
		{
			maxSum = sum;
			startM = start;
			endM = i;
		}
	}
	return maxSum;
}
