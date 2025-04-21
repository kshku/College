# Implement 8 puzzle game using Breadth First Search in Python.

import time
import os

class BoardState:
    def __init__(self, state: list[int]):
         self.state = state
         self.string = ''.join(map(str, state))
         self.print = ''
         for i in range(3):
            for j in range(3):
                self.print += f'{state[(i * 3) + j]}'
                self.print += ' | ' if j != 2 else ''
            self.print += '\n----------\n' if i != 2 else ''

    def __str__(self) ->str:
         return self.print

    def to_string(self):
         return self.string

    def get_next_states(self):
        idx = self.state.index(0)
        possible_swaps = [idx - 1, idx + 1, idx - 3, idx + 3]
        if idx < 3:
             possible_swaps.remove(idx - 3) # pop top

        if idx % 3 == 0:
             possible_swaps.remove(idx - 1) # pop left

        if idx % 3 == 2:
             possible_swaps.remove(idx + 1) # pop right

        if idx > 5:
             possible_swaps.remove(idx + 3) # pop bottom

        next_states = list()

        for swap in possible_swaps:
            new_state = self.state.copy()
            new_state[swap], new_state[idx] = new_state[idx], new_state[swap]
            next_states.append(BoardState(new_state))

        return next_states

class Puzzle:
    def __init__(self, start: BoardState, goal: BoardState):
        self.start = start
        self.goal = goal.to_string()

    def isGoalState(self, state: BoardState):
        return self.goal == state.to_string()

    def solve(self):
        queue: list[tuple[BoardState, list[BoardState]]] = [(self.start, [self.start])]
        visited: set[str] = set()

        while queue:
                state, path = queue.pop(0)

                if self.isGoalState(state):
                     return path

                if state.to_string() in visited:
                    continue

                visited.add(state.to_string())

                for next_state in state.get_next_states():
                    queue.append((next_state, path + [next_state]))

        return None

if __name__ == '__main__':
     start: BoardState = BoardState([1, 5, 3, 2, 4, 6, 7, 8, 0])
     goal: BoardState = BoardState([1, 2, 3, 4, 5, 6, 7, 8, 0])
     p: Puzzle = Puzzle(start, goal)
     path = p.solve()
     if path:
        step = 0
        for state in path:
            print("Step: %d" % (step))
            print(state)
            time.sleep(2)
            os.system('clear') # os.system('cls') for windows
            step += 1

        print(f"Total {step} steps")
     else:
        print("No solution")
