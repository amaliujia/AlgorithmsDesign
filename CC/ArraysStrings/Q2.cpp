/*
	reverse a null-terminated string
*/

	void reverse(char *str)
	{
		char *start = str;
		char temp;
		for(; *str != '\0';)
		{
			str++;
		}
		str -= 1;
		while(start < str)
		{
		   temp = *start;
		   *start = *str;
		   *str = temp;
		}
	}
