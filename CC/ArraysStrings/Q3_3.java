public boolean StringPermutation(String s, String t)
{
	if(s.length() != t.length())
	{
		return false;
	}
	int []letters = new int[256];
	char []s_array = s.toCharArray();
	for(char c : s_array)
	{
		letters[c]++;
	}
	char []t_array = s.toCharArray();
	for(char c : t_array)
	{
		if(--letters[c] < 0)
		{
			return false;
		}
	}
	return true;
}
