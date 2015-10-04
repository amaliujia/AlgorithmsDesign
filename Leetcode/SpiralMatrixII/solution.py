class Solution(object):
    def generateMatrix(self, n):
        matrix = list()
        for i in xrange(n):
            v = [0] * n
            matrix.append(v)
        if n == 0:
            return matrix
        
        row = n
        col = n
        xop = [0, 1, 0, - 1]
        yop = [1, 0, -1, 0]
        i = 0
        j = -1

        count = 0
        round = 0
        cur = 1
        while row > 0 and col > 0:
            if round % 2 == 0:
                count = col
                row -= 1
            else:
                count = row
                col -= 1
                
            while count > 0:
                i += xop[round]
                j += yop[round]
                matrix[i][j] = cur
                cur += 1
                count -= 1
            round = (round + 1) % 4

        return matrix
