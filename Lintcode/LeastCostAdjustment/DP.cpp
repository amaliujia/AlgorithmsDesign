class Solution {
  public:
    int MinAdjustmentCost(vector<int> A, int target) {
      vector<vector<int>> f(A.size(), vector<int>(101, 0));

      for(int j = 0; j < 101; j++){
        f[0][j] = abs(A[0] - j);
      }

      for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < 101; j++){
          f[i][j] = INT_MAX; 
          int cost = abs(A[i] - j);
          int low_bound = max(0, j - target);
          int upper_bound = min(100, j + target);
          for(int k = low_bound; k <= upper_bound; k++){
            f[i][j] = min(f[i][j], f[i-1][k] + cost);
          }
        }  
      }

      int result = INT_MAX;
      for(int i = 0; i < 101; i++){
        result = min(f[A.size() - 1][i], result);  
      }
      return result;
    }
};

