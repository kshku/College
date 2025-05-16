import os
import time

class TicTacToe:
    def __init__(self):
        self.state = [' '] * 9
        self.player = 1
        self.symbols = ['O', 'X']

    def __str__(self):
        # Format string for showing the board state
        return f" {self.state[0]} | {self.state[1]} | {self.state[2]}\n___|___|___\n {self.state[3]} | {self.state[4]} | {self.state[5]}\n___|___|___\n {self.state[6]} | {self.state[7]} | {self.state[8]}\n   |   |"

    def checkState(self):
        for i in range(3):
            # Check rows
            if self.state[i * 3] == self.state[i * 3 + 1] == self.state[i * 3 + 2]:
                return self.state[i * 3]
            # Check cols
            if self.state[i] == self.state[i + 3] == self.state[i + 6]:
                return self.state[i]

        # Check diagonals
        if (self.state[0] == self.state[4] == self.state[8]) or (self.state[2] == self.state[4] == self.state[6]):
            return self.state[4]

        # Draw
        if ' ' not in self.state:
            return None

        return ' '

    def mark(self, pos):
        if self.state[pos] != ' ':
            return False

        self.state[pos] = self.symbols[self.player % 2]
        self.player += 1
        return True

if __name__ == '__main__':
    print("Loading the game...")
    game = TicTacToe()
    time.sleep(1) # really, This is really big game, takes a little time to load 😂
    running = True
    result = ' '

    while running:
        print("Player1 [X] and Player2 [O]\n")
        print(f"Player{2 if game.player % 2 == 0 else 1} to play")
        print(game)
        pos = int(input(f"Enter position to mark [1-9]: "))
        if not game.mark(pos - 1):
            print("Invalid position!")
            time.sleep(1)
        os.system('clear') # if windows use os.system('cls')
        result = game.checkState()
        running = result == ' '

    if not result:
        print("Draw!")
    elif result == 'X':
        print("Player1 won!")
    else:
        print("Player2 won!")
