int DFS(vector<vector<int>>& matrix, int i, int j){
  if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] != '1'){
    return;
  }

  matrix[i][j] = '2';
  DFS(matrix, i-1, j);
  DFS(matrix, i, j-1);
  DFS(matrix, i+1, j);
  DFS(matrix, i, j+1);
}

int numIsland(vector<vector<int>>& matrix){
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix[0].size(); j++){
      if(matrix[i][j] == '1'){
        DFS(matrix, i, j);
      }
    }
  }
} 
