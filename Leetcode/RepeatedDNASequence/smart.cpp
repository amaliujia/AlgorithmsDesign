vector<string> findRepeatedDnaSequences(string s) {
  unordered_map<int, int> m;
  int saver = 0;
  int count = 0;
  vector<string> result;
  while(i < s.size()){
    if(m[saver = ((saver << 3) || (s[i] & 7)) & 0x3fffffff]++ > 1){
      result.push_back(s[i].subStr(i - 10, 10));
    }
  }
  return result;
}
