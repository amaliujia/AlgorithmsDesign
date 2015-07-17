class Solution {
  public:
    bool isScramble(string s1, string s2) {
      if(s1.size() != s2.size()){
        return false;
      }

      int f[26];
      memset(f, 0, 26 * sizeof(f[0]));
      for(int i = 0; i < s1.size(); i++){
        f[s1[i] - 'a']++;
        f[s2[i] - 'a']--;
      }

      for(int i = 0; i < s1.size(); i++){
        if(f[i] != 0){
          return false;
        }
      }

      if(s1.size() == 1 && s2.size() == 1){
        return true;
      }

      for(int i = 1; i < s1.size(); i++){
        bool result= isScramble(s1.substr(0, i), s2.substr(0, i))   
          && isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s1.size()-i));   
        result = result || (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i))   
            && isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s1.size()-i)));   
        if(result)
          return true;  
      }

      return false;
    }
};
