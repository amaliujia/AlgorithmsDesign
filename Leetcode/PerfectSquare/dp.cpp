class Solution {
  public:
    int numSquares(int n) {
      if(n == 0){
        return 0;
      } 

      vector<int> f(n+1, 0);
      for(int i = 0; i <= n; i++){
        f[i] = i;
        for(int j = 2; j <= sqrt(i); j++){
          if(i - j*j >= 0){
            f[i] = min(f[i], 1 + f[i - j*j]);
          }
        }
      }
      return f[n];
    }
};
