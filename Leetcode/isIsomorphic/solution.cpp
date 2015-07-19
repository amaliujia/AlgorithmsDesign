class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, char> table;
      unordered_map<char, char> reverse_table;
      unordered_map<char, char>::iterator iter;
      unordered_map<char, char>::iterator rev_iter;
      for(int i = 0; i < s.size(); i++){
        iter = table.find(s[i]);
        if(iter == table.end()){
          rev_iter = reverse_table.find(t[i]);
          if(rev_iter != reverse_table.end()){
            if(rev_iter->second != s[i]){
              return false;
            }
          }

          table.insert(std::pair<char, char>(s[i], t[i]));
          reverse_table.insert(std::pair<char, char>(t[i], s[i]));
        }else if(iter->second != t[i]){
          return false;
        }
      }
      return true;
    }
};
