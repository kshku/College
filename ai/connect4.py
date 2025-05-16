# Not completed
class Board:
    def __init__(self):
        self.width = 7
        self.height = 6
        self.state = [[0] * self.width for _ in range(self.height)]
        self.player = 0

        # self.state[5] = [1, 2, 1, 2, 1, 2, 1]
        # self.state[4] = [2, 1, 2, 1, 2, 1, 2]
        # self.state[3] = [1, 2, 1, 2, 1, 2, 1]

    def print(self):
        for i in range(self.height):
            print(self.state[i])

    def drop(self, col):
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

    def check(self, row, col):
        def check_direction(r, c, dr, dc):
            if self.state[r][c] == 0:
                return False
            for i in range(1, 4):
                nr, nc = r + (dr * i), c + (dc * i)
                if not (0 <= nr < self.height and 0 <= nc < self.width):
                    return False
                elif self.state[nr][nc] != self.state[r][c]:
                    return False

            return True

        def check_all_direction(r, c):
            directions = [(0, 1), (1, 0), (1, 1), (0, -1), (-1, 0), (-1, -1), (-1, 1), (1, -1)]
            for direction in directions:
                if check_direction(r, c, *direction):
                    return True

            return False

        if check_all_direction(row, col):
            return True

        positions_and_dir = [(0, 1, 0, -1), (1, 0, -1, 0), (1, 1, -1, -1), (-1, -1, 1, 1), (1, -1, -1, 1), (-1, 1, 1, -1), (0, -1, 0, 1), (-1, 0, 1, 0)]
        for params in positions_and_dir:
            if check_direction(row + params[0], col + params[1], params[2], params[3]):
                return True

        return False

    def check_draw(self):
        for row in self.state:
            if 0 in row:
                return False
        return True

    def play(self):
        end = False
        while not end:
            self.print()
            cell = self.drop(int(input(f"Enter the column for player {self.player % 2 + 1}: ")) - 1)
            if cell:
                if self.check(*cell):
                    end = True
                    self.print()
                    print(f"Player {(self.player - 1) % 2 + 1} Won!")
                if self.check_draw():
                    end = True
                    self.print()
                    print("Draw!")
            else:
                print("Invalid column")

if __name__ == "__main__":
    b = Board()
    b.play()
