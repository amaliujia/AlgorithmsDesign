class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        if len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0 or obstacleGrid[0][0] == 1:
            return 0
        mat = list();
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        for i in range(0, m):
            v = [0] * n
            mat.append(v)
        
        mat[0][0] = 1
        
        for i in range(0, m):
            for j in range(0, n):
                if obstacleGrid[i][j] == 1:
                    continue
                if i - 1 >= 0 and obstacleGrid[i-1][j] == 0:
                    mat[i][j] += mat[i-1][j]
                if j - 1 >= 0 and obstacleGrid[i][j-1] == 0:
                    mat[i][j] += mat[i][j-1]
        return mat[m-1][n-1]
