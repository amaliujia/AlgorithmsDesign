bool isOneEditDistance(string s, string t) {
  int m = s.length();
  int n = t.length();
  if(m > n){
    return isOneEditDistance(t, s);
  }

  if(n - m > 1){
    return false;
  }

  bool notMatch = false;
  for(int i = 0; i < m; i++){
    if(s[i] != t[i]){
      if(m == n) s[i] = t[i];
      else s.insert(i, 1, t[i]);
      notMatch = true;
      break;
    }
  }

  return (!notMatch && n - m == 1) || (notMatch && s == t);
}
