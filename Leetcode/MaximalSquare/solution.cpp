class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {

      if(matrix.size() == 0){
        return 0;
      }
      int dimension = 0;
      vector<vector<int>> f;
      int row = matrix.size();
      int col = matrix[0].size();
      for(int i = 0; i < row; i++){
        vector<int> v(col, 0);
        for(int j = 0; j < col; j++){
          if(matrix[i][j] == '1'){
            v[j] = 1;
          }else{
            v[j] = 0;
          }
        }
        f.push_back(v);
      }

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(f[i][j] && i != 0 && j != 0){
            f[i][j] = min(min(f[i-1][j], f[i][j-1]) ,f[i-1][j-1]) + 1;
          }

          dimension = max(dimension, f[i][j]);
        }   
      }
      return dimension * dimension;
    }
};
