class Solution {
  public:
    vector<int> grayCode(int n) {
      vector<int> res;
      res.push_back(0);

      for(int i = 1; i <= n; i++){
        int t = 1 << (i-1);
        int c = res.size();
        for(int j = c-1; j >= 0; j--){
          res.push_back(t + res[j]);
        }
      }
      return res;
    }
};
