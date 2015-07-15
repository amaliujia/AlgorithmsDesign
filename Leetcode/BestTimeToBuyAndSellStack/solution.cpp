class Solution {
  public:
    int maxProfit(int k, vector<int>& prices) {
      if(k >= prices.size() / 2){
        return quickSolve(prices);
      }

      vector<vector<int>> local;
      vector<vector<int>> global;

      for(int i = 0; i < prices.size(); i++){
        vector<int> v(k+1, 0);
        local.push_back(v);
        global.push_back(v);
      }

      for(int j = 1; j <= k; j++){
        for(int i = 1; i < prices.size(); i++){
          int diff = prices[i] - prices[i - 1];
          local[i][j] = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff);
          global[i][j] = max(global[i-1][j], local[i][j]);
        }
      }
      return global[prices.size()-1][k];
    }
  private:
    int quickSolve(vector<int>& prices) {
      int len = prices.size(), profit = 0;
      for (int i = 1; i < len; i++)
        // as long as there is a price gap, we gain a profit.
        if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
      return profit;
    }
};
