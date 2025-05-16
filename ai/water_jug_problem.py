class WaterJugSolver:
    def __init__(self, j1_cap, j2_cap, target):
        self.j1_cap, self.j2_cap, self.target = j1_cap, j2_cap, target
        self.visited = set()

    def solve(self, j1, j2):
        if (j1, j2) in self.visited:
            return False

        self.visited.add((j1, j2))

        if self.target in (j1, j2):
            print("Target reached!")
            return True

        j1_rem = self.j1_cap - j1
        j2_rem = self.j2_cap - j2

        operations = (
            (self.j1_cap, j2), # Fill j1
            (j1, self.j2_cap), # Fill j2
            (0, j2), # Empty j1
            (j1, 0), # Empty j2
            (j1 - min(j1, j2_rem), j2 + min(j1, j2_rem)), # Pour j1 to j2
            (j1 + min(j2, j1_rem), j2 - min(j2, j1_rem)), # Pour j2 to j1
        )

        for op in operations:
            if self.solve(*op):
                print(f"Operation: {op}")
                return True

        return False

if __name__ == '__main__':
    wjs = WaterJugSolver(4, 3, 2)
    if not wjs.solve(0, 0):
        print("Cannot solve!")
    else:
        print("Solved!")
