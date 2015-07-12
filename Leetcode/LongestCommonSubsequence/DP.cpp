class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
  int longestCommonSubsequence(string A, string B) {
    if(A.length() == 0 || B.length() == 0){
      return 0;
    }

    int f[A.size() + 1][B.size() + 1];
    for(int i = 1; i <= A.length(); i++){
      f[i][0] = 0;
    }
    for(int i = 1; i <= B.length(); i++){
      f[0][i] = 0;
    } 

    for(int i = 1; i <= A.length(); i++){
      for(int j = 1; j <= B.length(); j++){
        if(A[i - 1] == B[j - 1]){
          f[i][j] = f[i - 1][j - 1] + 1;
        }else{
          f[i][j] = max(f[i][j - 1], f[i - 1][j]);
        }
      }
    }
    return f[A.length()][B.length()];
  }
};
