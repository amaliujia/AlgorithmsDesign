// O(n^2) time
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int m = INT_MIN;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                int profit = prices[i] - prices[j];
                if(profit > m){
                    m = profit;
                }
            }
        }
        return m;
    }
};
