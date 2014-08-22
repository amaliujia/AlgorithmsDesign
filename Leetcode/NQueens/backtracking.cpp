// O(n) space
// O(n^n*n) time (we can express all solutions by n-trees, and every path from root to leaf is a solution. so we get n*n solutions.
//So totally we need O(n^n) time

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> v(n + 1, INT_MIN);
        nQueen(1, n, v, result);
        return result;
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
    
    void nQueen(int k, int n, vector<int> &v, vector<vector<string>> &result){
        for(int i = 1; i <= n; i++){
            if(place(k, i, v)){
                v[k] = i;
                if(k == n){
                    vector<string> tv;
                    for(int w = 1; w < v.size(); w++){
                        string ts(n, '.');
                        ts.replace(v[w] - 1, 1, "Q");
                        tv.push_back(ts);
                    }
                    result.push_back(tv);
                }else{
                    nQueen(k + 1, n, v, result);
                }
            }
        }
    }
};
