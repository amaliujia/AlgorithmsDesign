class Solution(object):
    def uniquePaths(self, m, n):
        if m == 0 or n == 0:
            return 0
        mat = list();
        for i in range(0, m):
            v = [0] * n
            mat.append(v)
        
        mat[0][0] = 1
        
        for i in range(0, m):
            for j in range(0, n):
                if i - 1 >= 0:
                    mat[i][j] += mat[i-1][j]
                if j - 1 >= 0:
                    mat[i][j] += mat[i][j-1]
        return mat[m-1][n-1]
        
