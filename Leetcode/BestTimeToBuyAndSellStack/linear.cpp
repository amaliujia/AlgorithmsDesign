int maxProfit(vector<int> &prices) {
   int min = INT_MAX;
   int max = 0;
   int n = prices.size();
    for(int i = 0; i < n; i++){
        if(prices[i] < min) min = prices[i];
           int profit = prices[i] - min;
           if(profit > max)    max = profit;
    }
    return max;
}
