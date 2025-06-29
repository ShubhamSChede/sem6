# Sample graph structure:
# Each node maps to its neighbors and their heuristic values
graph = {
    'A': {'B': 4, 'C': 3},
    'B': {'D': 2},
    'C': {'D': 4, 'E': 2},
    'D': {'G': 1},
    'E': {'G': 0},  # Goal node G has lowest heuristic
    'G': {}
}

# Heuristic values for each node (used to decide which neighbor is better)
heuristics = {
    'A': 5,
    'B': 4,
    'C': 3,
    'D': 2,
    'E': 1,
    'G': 0
}

def hill_climbing(start, goal):
    path = [start]
    current = start

    while current != goal:
        neighbors = graph.get(current, {})
        if not neighbors:
            print("No more neighbors. Local optimum reached.")
            break

        # Choose neighbor with lowest heuristic
        next_node = min(neighbors, key=lambda n: heuristics[n])

        # If no improvement, stop (plateau or local minimum)
        if heuristics[next_node] >= heuristics[current]:
            print("Stuck at local minimum. No better neighbor.")
            break

        path.append(next_node)
        current = next_node

    if current == goal:
        print("Goal reached!")
    else:
        print("Failed to reach goal.")

    print(path)

# ---------------- Run Example ----------------
start_node = 'A'
goal_node = 'G'

hill_climbing(start_node, goal_node)