class Solution:
    def isValidSudoku(self, board):
        rows=collections.defaultdict(set)
        cols=collections.defaultdict(set)
        grid=collections.defaultdict(set)
        for r in range(0,9):
            for c in range(0,9):
                if(board[r][c]=="."):
                    continue
                if (board[r][c] in rows[r] or
                board[r][c] in cols[c] or
                board[r][c] in grid[(r//3,c//3)]):
                    return False
                rows[r].add(board[r][c])
                cols[c].add(board[r][c])
                grid[(r//3,c//3)].add(board[r][c])
        return True
                

        