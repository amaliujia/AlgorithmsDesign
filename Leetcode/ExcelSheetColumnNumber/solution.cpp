class Solution {
  public:
    int titleToNumber(string s) {
      int re = 0;
      reverse(s.begin(), s.end());
      while(s.size() != 0){
        int n = s[s.size() - 1] - 'A' + 1;
        re = re * 26 + n;
        s.pop_back();
      }
      return re;
    }
};
