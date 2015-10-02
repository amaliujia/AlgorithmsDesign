bool isMatch(char* s, char* p) {
  if(*p == '\0'){
    return *s == '\0';
  }
  char *t = s;
  while(*t != '\0'){
    if(isMatch(t, p+1)) return true;
    t++;
  }

  if(*(p + 1) != '*'){
    return (*p == *s || (*p == '?' && *s != '\0')) && isMatch(s+1, p+1);
  }

  while(*p == *s || (*p == '?' && *s != '\0')){
    if(isMatch(s, p+2)) return true;
    s++;
  }

  return isMatch(s, p+2);
}
