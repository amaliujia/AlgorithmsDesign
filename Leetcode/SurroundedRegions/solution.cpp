class Solution {
  public:
    void solve(vector<vector<char>>& board) {
      int row = board.size();
      if(row == 0){
        return;
      }

      int col = board[0].size();

      vector<vector<bool>> visited;
      vector<vector<bool>> mark;
      for(int i = 0 ; i< row; i++){
        vector<bool> v(col, false);
        visited.push_back(v);
        mark.push_back(v);
      }

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(!visited[i][j] && board[i][j] == 'O'){
            if(bfs(board, mark, visited, i, j)){
              clean(board, mark);   
            }    
          }
        }
      }
    }

  private:
    void clean(vector<vector<char>>& board, vector<vector<bool>>& mark){
      int row = board.size();
      int col = board[0].size();

      for(int i = 0 ; i< row; i++){
        for(int j = 0; j < col; j++){
          if(mark[i][j] == true){
            mark[i][j] = false;
            board[i][j] = 'X';
          }
        }
      }        
    }

    bool bfs(vector<vector<char>>& board, vector<vector<bool>>& mark, vector<vector<bool>> &visited, 
        int i, int j){

      int row = board.size();
      int col = board[0].size();

      if(i + 1 >= row || i - 1 < 0 || j + 1 >= col || j - 1 < 0){
        return false;
      }
      visited[i][j] = true;
      mark[i][j] = true;

      bool r = true;

      if(!visited[i-1][j] && board[i-1][j] == 'O'){
        r &= bfs(board, mark, visited, i-1, j);
      } 

      if(!visited[i+1][j] && board[i+1][j] == 'O'){
        r &= bfs(board, mark, visited, i+1, j);
      } 

      if(!visited[i][j-1] && board[i][j-1] == 'O'){
        r &= bfs(board, mark, visited, i, j-1);
      } 

      if(!visited[i][j+1] && board[i][j+1] == 'O'){
        r &= bfs(board, mark, visited, i, j+1);
      } 

      return r;
    }
};
