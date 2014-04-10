/*
	time comlexity O(k*n^2)
*/
int partition(int s[], int n, int k)
{
	int m[MAXN+1][MAXN+1];
	int d[MAXN+1][MAXN+1];
	int p[MAXN+1];
	int cost;
 
	p[0] = 0;
	for(int i = 1; i <= n; i++)	p[i] = p[i-1] + s[i];
	
	for(int i = 1; i <= n; i++) m[i][1] = p[i]; 
	for(int j = 1; j <= k; j++) m[1][j] = p[1];	

	for(int i = 2; i <= n; i++){ //O(n)
		for(int j = 2; j <= k; j++){ // O(k)
			for(int x = 1; x <= (i-1); x++){
				// this needs linear time. we can take it simply as sum linearly				// thus this step is O(n)
				cost = max(m[x][j-1], p[i]-p[x]);
				if(m[i][j] > cost){
					m[i][j] = cost;
					d[i][j] = x;
				}
			}
		}
	}
	return cost;
}
