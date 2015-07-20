class Solution {
  public:
    string convertToTitle(int n) {
      string result;
      while(n){
        int r = n % 26;
        n /= 26;
        if(r)
          result.push_back('A' + r - 1);
        else{
          n--;
          result.push_back('Z');
        }
      }
      reverse(result.begin(), result.end());
      return result;
    }
};
