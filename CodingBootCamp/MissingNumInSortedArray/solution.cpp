int missingNumInSortedArry(vector<int>& v, int s, int e){
  int i = 0;
  int j = v.size() - 1;
  int exp = (s + e) / 2;
  int left = s;
  int right = e;

  int direct = -1;
  while(i < j - 1){
    int mid = (j - i) / 2 + i;
    if(v[mid] == exp){
      i = mid;
      exp = (v[i] + right) / 2;
      left = v[mid];
      direct = 1;
    }else{
      j = mid;
      exp = (left + v[j]) / 2;
      right = v[mid];
      direct = 2;
    }
  }

  int res = -1;
  if(v[i] != v[j] - 1){
    res =(v[i] + v[j]) / 2;
  }else{
    if (direct == 2) {
      res =  v[i] - 1;
    }else{
      res = v[j] + 1;
    }
  }

  return res;
}
