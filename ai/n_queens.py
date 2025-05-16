class NQueensSolver:
    def __init__(self, n):
        self.n = n
        self.board = [[0] * n for _ in range(n)]

    def is_safe(self, row, col):
        # Since we are placing the queens row by row, we just need to
        # look up to this row. Don't have to check entire board

        # Check for the current row
        for r in range(0, row): # Check upto this row
            if self.board[r][col]:
                return False

        # Check diagonally (Principal diagonal or main diagonal or major diagonal '\')
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if self.board[i][j]:
                return False

        # Check diagonally (Minor diagonal '/')
        for i, j in zip(range(row, -1, -1), range(col, self.n)):
            if self.board[i][j]:
                return False

        # It is safe to place queen here
        return True

    def solve(self, row):
        if row >= self.n: # All queens are placed
            return True

        for col in range(self.n):
            if self.is_safe(row, col):
                self.board[row][col] = 1 # safe, so place queen
                if self.solve(row + 1):
                    return True # We solved the problem
                # We couldn't solve the problem, this place
                # is not where we should place queen, check next column
                self.board[row][col] = 0

        # No solution
        return False

    def print_board(self):
        for row in self.board:
            print(row)

if __name__ == '__main__':
    nqs = NQueensSolver(int(input("Enter the number of queens: ")))
    if not nqs.solve(0):
        print("Couldn't solve!")
    else:
        nqs.print_board()
