//O(n^2) time
//O(n) space
class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<int> hash(n, 0);
        if(obstacleGrid[0][0] != 1) hash[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) 
                    hash[j] = 0;
                else if(j > 0)
                    hash[j] += hash[j - 1];       
            }
        }
        return hash[n - 1];
    }
}
