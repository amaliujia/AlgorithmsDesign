// O(n ^ 2) time
// O(n) space

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
       int n = grid[0].size();
       int m = grid.size();
       vector<int> f(n, 0);
       f[0] = grid[0][0];
       for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               if(i == 0 && j > 0){
                   f[j] = grid[i][j] + f[j - 1];
               }else if(j == 0 && i > 0){
                   f[j] = f[j] + grid[i][j];
               }else if(i != 0 && j != 0){
                   f[j] = grid[i][j] + min(f[j], f[j - 1]);
               }
           }
       }
        return f[n - 1];
    }
};
