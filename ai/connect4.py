# Not completed
class Board:
    def __init__(self):
        self.width = 7
        self.height = 6
        self.state = [[0] * self.width for _ in range(self.height)]
        self.player = 0

        self.state[5] = [1, 2, 1, 2, 1, 2]
        self.state[4] = [2, 1, 2, 1, 2, 1]
        self.state[3] = [1, 2, 1, 2, 1, 2]

    def print(self):
        for i in range(self.height):
            print(self.state[i])

    def drop(self, col):
        print(col)
        if not (-1 < col < self.width):
            return None

        if self.state[0][col] != 0:
            return None

        for i in range(self.height - 1):
            if self.state[i + 1][col] != 0:
                self.state[i][col] = (self.player % 2) + 1
                self.player += 1
                return (i, col)

        self.state[self.height - 1][col] = (self.player % 2) + 1
        self.player += 1
        return (self.height - 1, col)

    def check(self, r, c):
        # Check rows
        # Will break if not win
        for i in range(1, 4):
            if (c + i < 0) or (c + i >= self.width) or (self.state[r][c + i] != self.state[r][c + i - 1]):
                break
        else:
            # If didn't break player won
            return True

        # Will break if not win
        for i in range(1, 4):
            if (c - i < 0) or (c - i >= self.width) or (self.state[r][c - i] != self.state[r][c - i + 1]):
                break
        else:
            # If didn't break player won
            return True

        # Check cols
        # Will break if not win
        for i in range(1, 4):
            if (r + i < 0) or (r + i >= self.height) or (self.state[r + i][c] != self.state[r + i - 1][c]):
                break
        else:
            # If didn't break player won
            return True

        # Will break if not win
        for i in range(1, 4):
            if (r - i < 0) or (r - i >= self.height) or (self.state[r - i][c] != self.state[r - i + 1][c]):
                break
        else:
            # If didn't break player won
            return True

        for i in range(1, 4):
            if -1 < r + i < self.height and -1 < c + i < self.width:
                if self.state[r + i][c + i] != self.state[r + i - 1][c + i - 1]:
                    break
            else:
                break
        else:
            return True

        for i in range(1, 4):
            if -1 < r - i < self.height and -1 < c - i < self.width:
                if self.state[r - i][c - i] != self.state[r - i + 1][c - i + 1]:
                    break
            else:
                break
        else:
            return True


    def play(self):
        end = self.connected()
        while end == 0:
            self.print()
            cell = self.drop(int(input(f"Enter the column for player {self.player % 2 + 1}: ")) - 1)
            if cell:
                end = self.check(*cell)
            else:
                print("Invalid column")

        self.print()

        if end == 1:
            print("Player 1 WON!")
        elif end == 2:
            print("Player 2 WON!")
        else:
            print("Draw!")


if __name__ == "__main__":
    b = Board()
    b.play()
