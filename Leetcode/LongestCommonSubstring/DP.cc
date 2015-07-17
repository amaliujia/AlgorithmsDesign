int longestCommonSubstring(string &A, string &B) {
  vector<vector<int>> f;
  for(int i = 0; i <= A.size(); i++){
    vector<int> v(B.size()+1, 0);
    f.push_back(v);
  }

  int result = INT_MIN;

  for(int i = 0; i <= A.size(); i++){
    for(int j = 0; j <= B.size(); j++){
      if(i == 0 || j == 0){
        f[i][j] = 0;  
      }else if(A[i] == B[i]){
        f[i][j] = f[i - 1][j - 1] + 1;
      }else{
        f[i][j] = 0;
      }
      result = max(result, f[i][j]);
    }
  }
  return result;
}
