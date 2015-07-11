class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() <= 0){
            return false;
        }
        
        if(board.size() * board[0].size() < word.length()){
           return false; 
        }
        
        int row = board.size();
        int col = board[0].size();
        
        int *visited = new int[row * col];
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    for(int z = 0; z < row; z++){
                        for(int t = 0; t < col; t++){
                            visited[z * col + t] = 0;
                        }
                    }
                    if(bt(board, visited, word, 0, i, j)){
                        return true;
                    }
                    
                }
            }
        }
        delete visited;
        return false;
    }
    
private:
    bool bt(vector<vector<char>>& board, int *visited, string word, int matchlen, int row, int col){
        if(matchlen >= word.length()){
            return true;
        }
        
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){
            return false;   
        }
        
        int j = board[0].size();
        
        if(visited[row * j + col]){
            return false;
        }
        
        if(board[row][col] != word[matchlen]){
            return false;
        }
        
        visited[row * j + col] = 1;
        bool search = bt(board, visited, word, matchlen + 1, row + 1, col) ||
                      bt(board, visited, word, matchlen + 1, row, col + 1) ||
                      bt(board, visited, word, matchlen + 1, row - 1, col) ||
                      bt(board, visited, word, matchlen + 1, row, col - 1);
        if(!search){
           visited[row * j + col] = 0;   
        }
        return search;
    }
};
