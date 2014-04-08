public String zipSpacesHighPerformence(String s)
{
	int size = precount(s);
	if(size >= s.length())
	{
		return s;
	}
	StringBuffer str = new StringBuffer();
    int count = 1;
    char current = s.charAt(0);
    for(int i = 1; i < s.length(); i++)
    {
        if(current == s.charAt[i])
        {
            count++;
        }else{
            str.append(current);
			str.append(count);
            current = s.charAt[i];
            count = 1;
        }
    }  
    str.append(current);
    str.append(count); 
    return str.toString(); 
}

public int precount(String str)
{
	if(str == null || str.isEmpty())	return 0;
	int count = 1;
	char curr = str.charAt[0];
	int size = 0;
	for(int i = 1; i < str.length(); i++)
	{
		if(curr == str.charAt(i))
			count++;
		else{
			size += 1 + String.valueOf(count).length();
			count = 1;
			curr = str.charAt[i];
		}
	}
	size += 1 + String.valueOf(count).length();
	return size;
}
