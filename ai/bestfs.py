from queue import PriorityQueue

# Define a simple graph as adjacency list with heuristic values
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['G'],
    'F': [],
    'G': []
}

# Heuristic values (example: estimated cost to reach goal)
heuristic = {
    'A': 5,
    'B': 4,
    'C': 3,
    'D': 6,
    'E': 2,
    'F': 1,
    'G': 0   # goal
}

def best_first_search(start, goal):
    visited = set()
    pq = PriorityQueue()

    pq.put((heuristic[start], start))  # (priority, node)

    print("Best First Search Path:")

    while not pq.empty():
        h, current = pq.get()
        print(f"Visiting: {current} (heuristic: {h})")

        if current == goal:
            print("✅ Goal Reached!")
            return

        visited.add(current)

        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                pq.put((heuristic[neighbor], neighbor))

    print("🚫 Goal Not Reachable.")

# Run the search
start_node = 'A'
goal_node = 'G'
best_first_search(start_node, goal_node)