/*
test if a string has all unique characters with Bits
*/

public boolean testUniqueChar2(String s)
{
	int value = 0;
	for(int i = 0; i < s.length(); i++)
	{
		int single = s.charAt(i) - 'a';
		if(value & (1<<single) > 0 )
		{
			return false;
		}
		value |= (1<<single);
	}
	return true;
}
