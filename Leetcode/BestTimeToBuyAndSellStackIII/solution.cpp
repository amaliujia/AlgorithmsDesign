// O(n) time
// O(n) space
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0 || n == 1)    return 0;
        
        vector<int> f(n, 0);
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < minPrice)    minPrice = prices[i];
            int d = prices[i] - minPrice;
            if(d > maxProfit) maxProfit = d;
            f[i] = maxProfit;
        }
        
        int maxPrice = INT_MIN;
        int totalProfit = 0;
        for(int i = n - 1; i >= 0; i--){
            if(prices[i] > maxPrice)    maxPrice = prices[i];
            int d = maxPrice - prices[i];
            if((d + f[i]) > totalProfit) totalProfit = d + f[i]; 
        }
        return totalProfit;
    }

};
