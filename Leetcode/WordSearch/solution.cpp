bool wordSearch(vector<vector<char>>& grid, string word){
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[0].size(); j++){
      if(grid[i][j] == word[0]){  
      vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
      bool t = DFS(grid, word, 0, i, j, visited); 
      if(t) return true; 
      } 
    }
  }
  return false;
}


bool DFS(vector<vector<char>>& grid, string word, int idx, int i, int j, vector<vector<bool>>& visited){
  if(idx == word.length()){
    return true;
  }
  
  if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] != word[idx]){
    return false;
  } 

  visited[i][j] = true;
  if( DFS(grid, word, idx + 1, i-1, j, visited) ||
      DFS(grid, word, idx + 1, i+1, j, visited) ||
      DFS(grid, word, idx + 1, i, j-1, visited) ||
      DFS(grid, word, idx + 1, i, j+1, visited)) {
      return true;
  }
  visited[i][j] = false;
  return false;
}
