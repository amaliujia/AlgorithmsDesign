class Solution(object):
    def setZeroes(self, matrix):
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return
        dir = 0
        dir2 = 0
        for i in range(0, len(matrix)):
            for j in range(0, len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                    if i == 0:
                        dir = 1
                    if j == 0:
                        dir2 = 1
        
        for i in range(1, len(matrix)):
            if matrix[i][0] == 0:
                for j in range(0, len(matrix[0])):
                    matrix[i][j] = 0
                    
        for i in range(1, len(matrix[0])):
            if matrix[0][i] == 0:
                for j in range(0, len(matrix)):
                    matrix[j][i] = 0
        
        if matrix[0][0] == 0:
            if dir2 == 1:
                for i in range(0, len(matrix)):
                    matrix[i][0] = 0
            if dir == 1:
                for i in range(0, len(matrix[0])):
                    matrix[0][i] = 0
