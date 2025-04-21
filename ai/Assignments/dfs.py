class Node:
    def __init__(self, data, neighbours):
        self.data = data
        self.neighbours = neighbours

    def get_neighbours(self):
        return self.neighbours

    def get_data(self):
        return self.data

def dfs(start, goal):
    visited = set()
    stack = [(start, [start])]

    while stack:
        node, path = stack.pop()

        if node == goal:
            return path

        if node in visited:
            continue

        visited.add(node)

        for neighbour in node.get_neighbours():
            stack += [(neighbour, path + [neighbour])]


    return None

if __name__ == '__main__':
    n1 = Node(1, [])
    n2 = Node(2, [])
    n3 = Node(3, [])
    n9 = Node(9, [])
    n12 = Node(12, [n2])
    n7 = Node(7, [n1, n12])
    n5 = Node(5, [n9, n7])
    n11 = Node(11, [n3])
    n4 = Node(4, [n11])
    n8 = Node(8, [n5, n4])

    path = dfs(n8, n3)
    if path:
        for i in range(len(path) - 1):
            print(path[i].get_data(), end='')
            print('->', end='')
        print(path[len(path) - 1].get_data())
    else:
        print("No solution")
