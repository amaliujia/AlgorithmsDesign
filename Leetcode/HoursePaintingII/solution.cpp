class Solution {
  public:
    int minCostII(vector<vector<int>>& costs) {
      if(costs.size() == 0){
        return 0;
      } 

      int k = costs[0].size();
      int prevMin = 0;
      int prevSecMin = 0;
      int prevMinInd = -1;
      for(int i = 0; i < costs.size(); i++){
        int Min = INT_MAX-1;
        int SecMin = INT_MAX;
        int MinInd = -1;          
        for(int j = 0; j < k; j++){
          int temp = costs[i][j] + ((j == prevMinInd) ? prevSecMin : prevMin);
          if(temp < Min){
            SecMin = Min;
            Min = temp;
            MinInd = j;

          }else if(temp < SecMin){
            SecMin = temp;
          }
        }
        prevMin = Min;
        prevSecMin = SecMin;
        prevMinInd = MinInd;
      }

      return prevMin;
    }
};
