class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = list()
        row = len(matrix)
        if row == 0:
            return result
        col = len(matrix[0])
        xop = [0, 1, 0, - 1]
        yop = [1, 0, -1, 0]
        i = 0
        j = -1
        
        count = 0
        round = 0
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
                result.append(matrix[i][j])
                count -= 1
            round = (round + 1) % 4
        
        return result
        
