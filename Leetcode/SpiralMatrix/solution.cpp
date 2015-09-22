class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> result;
      if(matrix.size() == 0){
        return result;
      }

      const int nc[4] = {0, 1, 0, -1};
      const int yc[4] = {1, 0, -1, 0};

      int row = matrix.size(); 
      int col = matrix[0].size();

      int x = 0, y = -1;
      int i = 0;
      int k = 0;
      while(row > 0 && col > 0){

        if(i % 2 == 0){
          k = col;
          row--;
        }else{
          k = row;
          col--;
        }

        while(k > 0){
          x += nc[i];
          y += yc[i];
          result.push_back(matrix[x][y]);
          k--;

        }

        i = (i + 1) % 4;
      }
      return result;
    }
};
