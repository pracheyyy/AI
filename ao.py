
def ao_star(graph, heuristic, node):
    print("Visiting:", node)

    if node not in graph or not graph[node]:
        return heuristic[node]

    min_cost = float('inf')
    best_path = None

    for option in graph[node]:
        cost = 0

        for child, edge_cost in option:
            cost += edge_cost + heuristic[child]

        if cost < min_cost:
            min_cost = cost
            best_path = option

    heuristic[node] = min_cost

    print("Best path from", node, ":", best_path)

    total_cost = 0
    for child, edge_cost in best_path:
        total_cost += edge_cost + ao_star(graph, heuristic, child)

    return total_cost


graph = {
    'A': [
        [('B', 1), ('C', 1)],  # AND: B and C
        [('D', 3)]             # OR: D
    ],
    'B': [
        [('E', 2)],
        [('F', 3)]
    ],
    'C': [
        [('G', 2)]
    ],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}

heuristic = {
    'A': 1,
    'B': 2,
    'C': 2,
    'D': 0,
    'E': 0,
    'F': 0,
    'G': 0
}

cost = ao_star(graph, heuristic, 'A')
print("Final cost:", cost)
