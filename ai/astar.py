def AStarAlgo(start, goal, graph, hueristic):
    h = hueristic
    # Store path and path cost along with node like ('A', ['A'], 14)
    open_list = [(start, [start], h[start])]

    while open_list:
        print(f"open_list: {open_list}")

        # Find node with least f(n)
        node, path, nf = open_list[0]
        # nf => new f value (path cost)
        for (v, p, f) in open_list:
            if f < nf:
                node, path, nf = v, p, f

        # Goal check
        if node == goal:
            return (path, nf)

        open_list.remove((node, path, nf))
        print("Popped:", (node, path, nf))

        print(f"Neighbours of {node}: {graph.get(node, [])}")

        # Add neighbours to openlist
        for (v, w) in graph.get(node, []):
            # v -> vertex (neighbour node)
            # path + [v] = adding to path like ['A'] + ['B'] = ['A', 'B']
            # (nf - h[node]) -> subtract hueristic from path cost to get the g(n)
            # + w -> adding weight to g(n) calculated => g(v)
            # + h[v] -> adding the heuristic of neighbour
            open_list.append((v, path + [v], (nf - h[node]) + w + h[v]))

        print()

    return None

if __name__ == '__main__':
    graph = {
        'A': [('B', 4), ('C', 3)],
        'B': [('F', 5), ('E', 12)],
        'C': [('E', 10), ('D', 7)],
        'D': [('C', 7), ('E', 2)],
        'E': [('B', 12), ('Z', 5)],
        'F': [('B', 5), ('Z', 16)]
    }

    hueristic = {'A': 14, 'B': 12, 'C': 11, 'D': 6, 'E': 4, 'F': 11, 'Z': 0}

    path, cost = AStarAlgo('A', 'Z', graph, hueristic)

    print()

    if not path:
        print("No solution")
    else:
        print(f"Path: {path}\nCost: {cost}")
