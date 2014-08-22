ass Solution {
public:
    int totalNQueens(int n) {
      vector<int> v(n + 1, INT_MIN);
      int count = 0;
      nQueen(1, n, v, count);
      return count;
    }
    bool place(int k, int j, vector<int> &v){
        for(int i = 1; i < k; i++){
            if(v[i] == j)   return false;
            if(abs(v[i] - j) == abs(k - i)){
                return false;
            }
        }
        return true;
    }
    
    void nQueen(int k, int n, vector<int> &v, int &count){
        for(int i = 1; i <= n; i++){
            if(place(k, i, v)){
                v[k] = i;
                if(k == n){
                    count++;
                }else{
                    nQueen(k + 1, n, v, count);
                }
            }
        }
    }
};
