int numDistinct(string S, string T){
	int m = S.size(), n = T.size();
	int f[m + 1][n + 1];
	for(int i = 0; i < m; i++){
		f[i][n] = 1;
	}	
	for(int i = 0; i < n; i++){
		f[m][i] = 0;
	}
	for(int i = m - 1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			if(S[i] == T[j]){
				f[i][j] = f[i + 1][j] + f[i + 1][j + 1];	
			}else{
				f[i][j] = f[i + 1][j];
			}
		}
	}
	return f[0][0];
}
