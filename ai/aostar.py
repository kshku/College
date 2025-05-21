graph = {
    'A': [[('B', 1)], [('C', 1)]],
    'B': [[('D', 1), ('E', 1)]],
    'C': [[('G', 2)]],
    'D': [], 'E': [], 'G': []
}

heuristic = {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0, 'G': 0}

solution_graph = {}

def get_best_children(node):
    min_cost = float('inf')
    best = None
    for children in graph[node]:
        cost = sum(heuristic[c] + v for c, v in children)
        if cost < min_cost:
            min_cost = cost
            best = children

    return min_cost, best

def aoStar(node):
    if not graph[node]:
        return

    cost, best = get_best_children(node)
    heuristic[node] = cost
    solution_graph[node] = best
    for child, _ in best:
        if solution_graph:
            aoStar(child)

def print_solution_graph(node, indent=' '):
    if node not in solution_graph:
        return
    children = solution_graph[node]
    for child, _ in children:
        print(f"{indent}{node} -> {child}")
        print_solution_graph(child, indent='\t')

aoStar('A')
print('Solution path:')
print_solution_graph('A')
