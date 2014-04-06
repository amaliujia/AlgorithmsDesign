#include <map>

int stringPermutation(char *s, char *t)
{
    
    map<char,int> m;
    for(int i = 0; i < 256; i++)
	{
		map[(char)i] = 0;
	}
	while(*s != '\0')
    {
        m[*s]++;
        s++;
    }
    while(*t != '\0')
    {
   		m[*t]--; 
        t++;
    }
	for(int i = 0; i < 256; i++)
	{
		if(m[(char)i] != 0)
		{
			return 0;
		}
	}
    return 1;
}
