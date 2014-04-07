public class solution{
	public String func(String s)
	{
		char []arr = s.toCharArray();
        int len = s.length();
        int trueLen = length;
        for(int i = 0; i < trueLen; i++)
        {
        	if(arr[i] != ' ')
        	{
        		continue;
        	}else{
        		for(int j = trueLen + 2; j > i + 2; j--)
        		{
        			arr[j] = arr[j-2];
        		}
        		trueLen += 2;
        		arr[i] = '%';
        		arr[i+1] = '2';
        		arr[i+2] = '0';
        	}
        }
        for(int i = trueLen; i < len; i++)
        {
        	arr[i] = '\0';
        }
        return new String(arr);
	}
};
