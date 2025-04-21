class Graph:
    def __init__(self, graph):
        self.graph = graph

    def get_neighbours(self, node):
        return self.graph[node]

def get_top(pq):
    top = 0
    for i in range(len(pq)):
        if pq[i][1] < pq[top][1]:
            top = i

    return pq.pop(top)

def ucs(start, goal, graph):
    visited = set()
    priority_queue = [(start, 0, [start])]

    while priority_queue:
        node, cost, path = get_top(priority_queue)

        if node == goal:
            return (path, cost)

        if (node, cost) in visited:
            continue

        visited.add((node, cost))

        for n, c in graph.get_neighbours(node):
            priority_queue.append((n, cost + c, path + [n]))

    return None

if __name__ == '__main__':
    graph = Graph({
        'A': [('B', 5), ('D', 10)],
        'B': [('F', 15), ('C', 4)],
        'C': [('E', 8)],
        'D': [('F', 11)],
        'E': [],
        'F': [('E', 4)]
    })
    res = ucs('A', 'E', graph)
    if res:
        path, cost = res
        print("Path: ", end='')
        for i in range(len(path) - 1):
            print(f'{path[i]}->', end='')
        print(f'{path[len(path) - 1]}')
        print(f'Cost: {cost}')
    else:
        print("No solution")
