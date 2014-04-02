#define MATCH	0
#define INSERTION	1
#define	DELETION	2
int StringCompare(char *s, char *t, int i, int j)
{
	int k;
	int opt[3];
	int lowest;
	
	opt[MATCH] = StringCompare(s, t, i-1, j-1) + match(s[i],t[j]);
	opt[INSERTION] = StringCompare(s, t, i-1, j) + indel(s[i]);
	opt[DELETION] = StringCompare(s, t, i, j-1) + indel(t[j]); 
	
	lowest = opt[MATCH];
	for(int l= INSERTION; i<=DELETION; i++)
	{
		if(opt[l] < lowest)	lowest = opt[i]; 
	}
	return lowest;
}
