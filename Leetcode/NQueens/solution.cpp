vector<vector<string>> solveNQueens(int n){
	vector<vector<string>> result;
	int row[n];
	int col[n];
	dfs(0, n, row, col, result);
	return result;	
}

void dfs(int r, int n, int row[], int col[], vector<vector<string>> &result){
	int i, j;
	if(r == n){
		vector<string> go;
		for(i = 0; i < n; i++){
			string temp(n, '.');
			temp[row[i]] = 'Q';
			go.push_back(temp);
		}
		result.push_back(go);
	}
	for(i = 0; i < n; i++){
		if(col[i] == 0){
			for(j = 0; j < r; j++){
				if(abs(j - r) == abs(i - row[j]))
					break;
				if(j == r){
					row[r] = i;
					col[i] = 1;
					dfs(r + 1, n);
					col[i] = 0;
					row[r] = 0;
				}
			}
		}
	}
}
