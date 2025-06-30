def simple_hill_climb(graph, heuristics, start, goal):
    print("\nSimple Hill Climbing Path:")
    current = start
    path = [current]
    while current != goal:
        neighbors = graph.get(current, [])
        next_node = None
        for neighbor in neighbors:
            if heuristics[neighbor] < heuristics[current]:
                next_node = neighbor
                break
        if not next_node:
            print("Stuck at:", current)
            break
        path.append(next_node)
        current = next_node
    print(" -> ".join(path))

def steepest_ascent_hill_climb(graph, heuristics, start, goal):
    print("\nSteepest Ascent Hill Climbing Path:")
    current = start
    path = [current]
    while current != goal:
        neighbors = graph.get(current, [])
        best = None
        for neighbor in neighbors:
            if neighbor != current:
                if best is None or heuristics[neighbor] < heuristics[best]:
                    best = neighbor
        if best is None or heuristics[best] >= heuristics[current]:
            print("Stuck at:", current)
            break
        path.append(best)
        current = best
    print(" -> ".join(path))

graph = {}
heuristics = {}

n = int(input("Enter number of nodes: "))
for _ in range(n):
    node = input("Enter node name: ")
    h = int(input(f"Heuristic of {node}: "))
    heuristics[node] = h
    graph[node] = []

e = int(input("Enter number of edges: "))
for _ in range(e):
    u, v = input("Enter edge (from to): ").split()
    graph[u].append(v)
    graph[v].append(u)  # If undirected

start = input("Enter start node: ")
goal = input("Enter goal node: ")

simple_hill_climb(graph, heuristics, start, goal)
steepest_ascent_hill_climb(graph, heuristics, start, goal)

# Enter number of nodes: 10
# Enter node name: s
# Heuristic of s: 21
# Enter node name: a
# Heuristic of a: 14
# Enter node name: b
# Heuristic of b: 16
# Enter node name: c
# Heuristic of c: 8
# Enter node name: d
# Heuristic of d: 12
# Enter node name: f
# Heuristic of f: 7
# Enter node name: g
# Heuristic of g: 4
# Enter node name: h
# Heuristic of h: 12
# Enter node name: i
# Heuristic of i: 6
# Enter node name: j
# Heuristic of j: 0
# Enter number of edges: 16
# Enter edge (from to): s a
# Enter edge (from to): s b
# Enter edge (from to): s c
# Enter edge (from to): s d
# Enter edge (from to): a f
# Enter edge (from to): a g
# Enter edge (from to): c f
# Enter edge (from to): c g
# Enter edge (from to): d g
# Enter edge (from to): d h
# Enter edge (from to): b g
# Enter edge (from to): b h
# Enter edge (from to): f i
# Enter edge (from to): g i
# Enter edge (from to): g j
# Enter edge (from to): h j
# Enter start node: s
# Enter goal node: j

# Simple Hill Climbing Path:
# s -> a -> f -> i -> g -> j

# Steepest Ascent Hill Climbing Path:
# s -> c -> g -> j
