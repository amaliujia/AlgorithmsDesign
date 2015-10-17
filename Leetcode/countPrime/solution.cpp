class Solution {
  public:
    int countPrimes(int n) {
      int count;
      int visit[n];
      memset(visit, 0, sizeof(visit));
      for(int i = 2; i < n;  i++){
        if(visit[i]){
          continue;
        }
        if(isPrime(i)){
          count++;
        } 
        for(int j = i + i; j <= n; j += i){
          visit[j] = 1;
        }
      }      

      return count;
    }

  private:
    bool isPrime(int n){
      for(int i = 2; i <= n / 2; i++){
        if(n % i == 0){
          return false;
        }
      }
      return true;
    }
};
