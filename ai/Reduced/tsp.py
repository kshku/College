from sys import maxsize
from itertools import permutations

graph = [
    [0, 10, 15, 20],
    [10, 0, 35, 25],
    [15, 35, 0, 30],
    [20, 25, 30, 0]
]

v = len(graph) # or v = 4

def calculate_cost(start, path):
    cost = 0
    current_node = start
    for node in path:
        cost += graph[current_node][node]
        current_node = node
    cost += graph[current_node][start]
    return cost

def solve(start):
    min_cost = maxsize
    nodes = [i for i in range(v) if i != start]
    for path in permutations(nodes):
        min_cost = min(min_cost, calculate_cost(start, path))
    return min_cost

print(f"Minimum cost: {solve(0)}")
