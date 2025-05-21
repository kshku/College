n = int(input("Enter the number of queens: "))
board = [[0] * n for _ in range(n)]

def is_safe(row, col):
    for r in range(0, row): # Check upto this row
        if board[r][col]:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j]:
            return False
    return True

def solve(row):
    if row >= n: # All queens are placed
        return True
    for col in range(n):
        if is_safe(row, col):
            board[row][col] = 1 # safe, so place queen
            if solve(row + 1):
                return True # We solved the problem
            board[row][col] = 0
    return False

if not solve(0):
    print("Couldn't solve!")
else:
    for row in board:
        print(row)
