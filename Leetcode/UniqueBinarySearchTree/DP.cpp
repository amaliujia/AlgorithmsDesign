class Solution {
  public:
    int numTrees(int n) {
      vector<int> f(n + 1, 0);
      f[0] = 1;
      f[1] = 1;

      for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
          f[i] += f[j] * f[i - j - 1];
        }
      }
      return f[n];
    }
};
