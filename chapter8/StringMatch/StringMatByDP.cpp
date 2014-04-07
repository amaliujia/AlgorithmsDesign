#define MATCH		0
#define INSERTION	1
#define	DELETION	2
#define MAXLEN		1000

typedef struct{
	int cost;
	int action;

}cell;

cell mat[MAXLEN+1][MAXLEN+1];


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
	goal_cell(s, t, &i, &j);
	return mat[i][j].cost;
}

int match(char c, char d)
{
	if(c == d)
	{
		return 0;
	}else{
		return 1;	
	}
}

int indel(char c)
{
	return 1;
}

void goal_cell(char *s, char *t, &i, &j)
{
	*i = strlen(s);
	*j = strlen(j);
}

void reconstruct_path(char *s, char *t, int i, intj)
{
	if(mat[i][j].parent == -1)  return;

	if(mat[i][j].parent == MATCH)
	{
		reconstruct_path(s, t, i-1, j-1);
		match_out(s, t, i ,j);
		return;
	}

	if(mat[i][j].parent == INSERTION)
	{
		reconstruct_path(s, t, i, j-1);
		insert_rev(t, j);
		return;
	}

	if(mat[i][j].parent == DELETION)
	{
		reconstruct_path(s, t, i-1, j);
		delet_rev(s, i);
		return;
	}
	return;
}

void insert_rev(char *c, int i)
{
	printf("I");
}

void delete_rev(char *c, int j)
{
	printf("D");
}

void match(char *c, char *t, int i, int j)
{
	if(s[i] == s[j]) printf("M");
	else	printf("S");
}
