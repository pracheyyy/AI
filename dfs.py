def water_jug(capacity1, capacity2, target):
    visited = set()

    def dfs(x, y, path):
        if (x, y) in visited:
            return False

        visited.add((x, y))
        path.append((x, y))

        if x == target or y == target:
            return True

        next_states = [
            (capacity1, y), 
            (x, capacity2),  
            (0, y),          
            (x, 0),         
            (x - min(x, capacity2 - y), y + min(x, capacity2 - y)),
            (x + min(y, capacity1 - x), y - min(y, capacity1 - x))
        ]

        for nx, ny in next_states:
            if dfs(nx, ny, path):
                return True

        path.pop()
        return False

    path = []

    if dfs(0, 0, path):
        print("Solution found:")
        for state in path:
            print(state)
    else:
        print("No solution possible")

water_jug(4, 3, 2)
