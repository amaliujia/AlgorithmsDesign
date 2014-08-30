// O(n) time
int maxProfit(vector<int> &prices) {
   int left = 0, right = 0;
   int n = prices.size();
   int profit = 0;
      
   for(int i = 1; i < n; i++){
       if(prices[i] > prices[i - 1]){
           right = i;
       }else{
           if((right - left) >= 1){
               profit += (prices[right] - prices[left]);
           }
           right = i;
           left = i;
       }
   }
   if((right - left) >= 1){ 
      profit += (prices[right] - prices[left]);
   }
   return profit;
}
