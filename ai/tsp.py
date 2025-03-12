from sys import maxsize
from itertools import permutations

class TSPSolver:
    def __init__(self, v, graph):
        self.v = v
        self.graph = graph

    def calculate_cost(self, start, path):
        cost = 0
        current_node = start

        for node in path:
            cost += self.graph[current_node][node]
            current_node = node

        # Going back to the starting node
        cost += self.graph[current_node][start]

        return cost

    def solve(self, start):
        min_cost = maxsize

        nodes = [i for i in range(self.v) if i != start]

        for path in permutations(nodes):
            min_cost = min(min_cost, self.calculate_cost(start, path))

        return min_cost

if __name__ == '__main__':
    graph = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]
    tsps = TSPSolver(4, graph)
    print(f"Minimum cost: {tsps.solve(0)}")
