/*
	test if a string has all unique characters with Hashtable
*/
public boolean testUniqueChar(String s)
	{
		Hashtable<Object, Object> table = new Hashtable<Object, Object>();
		for(int i = 0; i < s.length(); i++)
		{
			char c = s.charAt(i);
			if(table.get(c) != null)
			{
				return false;
			}else{
				table.put(c, 1);
			}
		}
		return true;
	}
