public String zipString(String s)
{
	char[] arr = s.toCharArray();
	int start = 0;
	int end = 0;
	int len = s.length();
	char flag = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(flag == 0)
		{
			flag = arr[i];
			start = i;
			end = i;
		}else if(flag == arr[i])
		{
			end++;
		}else{
			for(int j = end + 1; j < len; j++)
			{
				arr[j-(end-start)+1] = arr[j];
			}
			len -= (end-start-1);	
			arr[start+1] = (end-start+1) + "";
			flag = 0;
			i = start + 1;	
		}
	}
	for(int i = len; i < s.length(); i++)
	{
		arr[i] = '\0';
	}
	return new String(arr);
}
