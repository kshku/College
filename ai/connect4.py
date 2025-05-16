import os

class Board:
    def __init__(self):
        self.width = 7
        self.height = 6
        self.state = [[0] * self.width for _ in range(self.height)]
        self.player = 0

        # To test things

        # self.state[5] = [1, 2, 1, 2, 1, 2, 1]
        # self.state[4] = [2, 1, 2, 1, 2, 1, 2]
        # self.state[3] = [1, 2, 1, 2, 1, 2, 1]
        # self.state = [
        #     [1, 1, 2, 2, 1, 0, 2],
        #     [2, 2, 1, 1, 2, 2, 1],
        #     [1, 1, 2, 2, 1, 1, 2],
        #     [2, 2, 1, 1, 2, 2, 1],
        #     [1, 1, 2, 2, 1, 1, 2],
        #     [2, 2, 1, 1, 2, 2, 1],
        # ]

    def print(self):
        for i in range(self.height):
            print(self.state[i])

    def drop(self, col):
        # Out of bound?
        if not (-1 < col < self.width):
            return None

        # Column already full?
        if self.state[0][col] != 0:
            return None

        # Find the row which is empty at this column
        # Try to visualize, you will get it
        for i in range(self.height - 1):
            if self.state[i + 1][col] != 0:
                self.state[i][col] = (self.player % 2) + 1
                self.player += 1
                return (i, col)

        self.state[self.height - 1][col] = (self.player % 2) + 1
        self.player += 1
        return (self.height - 1, col)

    def check(self, row, col):
        # Check whether a player won

        if self.state[row][col] == 0:
            return False

        # Helper function to calcuate the number of pieces of same player that are adjacent to this cell
        def count_direction(dr, dc):
            count = 1
            for step in [1, -1]:
                r, c = row + dr * step, col + dc * step
                while 0 <= r < self.height and 0 <= c < self.width and self.state[r][c] == self.state[row][col]:
                    count += 1
                    r += dr * step
                    c += dc * step
            return count

        # directions: horizontal, vertical, major diagonal, minor diagonal
        directions = [(0, 1), (1, 0), (1, 1), (1, -1)]
        # calculate the number of player's pieces in the given direction
        for dr, dc in directions:
            if count_direction(dr, dc) >= 4:
                return True

        return False


    def check_draw(self):
        # Check whether game is draw
        for row in self.state:
            if 0 in row:
                return False
        return True

    def play(self):
        winner = 0
        invalid = False
        while winner == 0:
            os.system('clear')
            if invalid:
                invalid = False
                print("Invalid input, enter again")
            self.print()
            cell = self.drop(int(input(f"Enter the column for player {self.player % 2 + 1}: ")) - 1)
            if not cell:
                invalid = True
            elif self.check(*cell):
                winner = (self.player - 1) % 2 + 1
            elif self.check_draw():
                winner = 3

        self.print()
        if winner == 3:
            print("Draw!")
        else:
            print(f"Player {winner} Won!")


if __name__ == "__main__":
    b = Board()
    b.play()
