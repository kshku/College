state = [' '] * 9
player = 0
symbols = ['X', 'O']

def print_board():
        print(f" {state[0]} | {state[1]} | {state[2]}\n___|___|___\n {state[3]} | {state[4]} | {state[5]}\n___|___|___\n {state[6]} | {state[7]} | {state[8]}\n   |   |")

def checkState():
    for i in range(3):
        if state[i * 3] == state[i * 3 + 1] == state[i * 3 + 2]:
            return state[i * 3]
        if state[i] == state[i + 3] == state[i + 6]:
            return state[i]
    if (state[0] == state[4] == state[8]) or (state[2] == state[4] == state[6]):
        return state[4]
    if ' ' not in state:
        return None
    return ' '

def mark(pos):
    global player
    if state[pos] != ' ':
        return False
    state[pos] = symbols[player % 2]
    player += 1
    return True

print("Loading the game...")
print("Player1 [X] and Player2 [O]\n")
result = ' '

while result == ' ':
    print_board()
    print(f"Player{player % 2 + 1} to play")
    pos = int(input(f"Enter position to mark [1-9]: "))
    if not mark(pos - 1):
        print("Invalid position!")
    result = checkState()

print_board()
if not result:
    print("Draw!")
elif result == 'X':
    print("Player1 won!")
else:
    print("Player2 won!")
