    # @param board, a 9x9 2D array
    # Solve the Sudoku by modifying the input board in-place.
    # Do not return any value.
def solveSudoku(board):
    def isValidSudoku(board):
        for row in board:
            for k in range(1,10):
                if row.count(str(k)) > 1:
                    return False
        for i in range(9):
            num = []
            for j in range(9):
                num.append(board[j][i])
                for k in range(1,10):
                    if num.count(str(k)) > 1:
                        return False
                        
        for i in range(0,7,3):
            for j in range(0,7,3):
                num = []
                num.append(board[i][j:j+3])
                num.append(board[i+1][j:j+3])
                num.append(board[i+2][j:j+3])
                for k in range(1,10):
                    if num.count(str(k)) > 1:
                        return False
        return True
                    
    def _solveSudoku(board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for k in range(1,10):
                        board[i] = board[i][0:j]+str(k)+board[i][j+1:9]
                        if isValidSudoku(board) and _solveSudoku(board):
                            return True
                    board[i] = board[i][0:j]+"."+board[i][j+1:9]
                    return False
        return True
        
    _solveSudoku(board)
    print(board)

solveSudoku(["...42..6.","32...8...",".41..7...","..9..1..3",".8.....1.","6..8..7..","...7..52.","...5...48",".9..46..."])
    