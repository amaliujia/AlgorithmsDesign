/*
	if we are not allowed to use StringBuffer(What a pity), we can still use String to achieve O(p);
*/

public String zipSpacesHighPerformence(String s)
{
    int size = precount(s);
    if(size >= s.length())
    {
        return s;
    }
    char []result = new char[size];
	int count = 1;
    char current = s.charAt(0);
    int index = 0;
	result[index++] = current;
    for(int i = 1; i < s.length(); i++)
    {
        if(current == s.charAt[i])
        {
            count++;
        }else{
			String tems = String.valueOf(count);
			for(int j = 0; j < tems.length(); j++)
			{
				result[index++] = tems.charAt(j);
			} 
			current = s.charAt[i];
            count = 1;
        }
    }
    String tems = String.valueOf(count);
    for(int j = 0; j < tems.length(); j++)
    {
       result[index++] = tems.charAt(j);
    }

    return String.valueOf(result);
}

public int precount(String str)
{
    if(str == null || str.isEmpty())    return 0;
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
