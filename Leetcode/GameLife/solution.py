class Solution(object):
    def gameOfLife(self, board):
        if len(board) == 0 or len(board[0]) == 0:
            return
        xop = [0,-1,-1,-1,0,1,1,1]
        yop = [-1,-1,0,1,1,1,0,-1]
        row = len(board)
        col = len(board[0])
        for i in range(0, row):
            for j in range(0, col):
                live = 0
                for z in range(0, 8):
                    nx = i + xop[z]
                    ny = j + yop[z]
                    if nx < 0 or nx >= row:
                        continue
                    if ny < 0 or ny >= col:
                        continue
                    if board[nx][ny] == 1 or board[nx][ny] == 3:
                        live += 1
                if board[i][j] == 1 and (live > 3 or live < 2):
                    board[i][j] = 3
                elif board[i][j] == 0 and live == 3:
                    board[i][j] = 4
        for i in range(0, row):
            for j in range(0, col):
                if board[i][j] == 3:
                    board[i][j] = 0
                elif board[i][j] == 4:
                    board[i][j] = 1
