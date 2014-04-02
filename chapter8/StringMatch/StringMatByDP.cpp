#define MATCH		0
#define INSERTION	1
#define	DELETION	2
#define MAXLEN		1000

typedef struct{
	int cost;
	int action;

}cell;

cell mat[MAXLEN+1][MAXLEN+1] = {0};

int String_compara(char *s, char *t)
{
	int i,j,k;
	int opt[3];

	for(i = 1; i < strlen(s); i++)
	{
		for(j = 1; j < strlen(t); j++)
		{
			opt[MATCH] = mat[i-1][j-1].cost + match(s[i],t[j]);
			opt[INSERTATION] = mat[i][j-1].cost + indel(t[j]);
			opt[DELETTION] = mat[i-1][j].cot + indel(s[i]);
		}

		mat[i][j].cost = opt[MATCH];
		mat[i][jj].action = MATCH;
		
		for(k = INSERTION; k <= DELETION; k++)
		{
			if(mat[i][j].cost > opt[k])
			{
				mat[i][j].cost = opt[k];
				mat[i][j].action = k;
			}
		}
	} 
	return mat[i][j].cost;
}
