import heapq

def a_star(graph, heuristics, start, goal_set):
    queue = [(heuristics[start], 0, start, [start])]
    visited = set()
    iteration = 1

    while queue:
        est_total, cost, node, path = heapq.heappop(queue)
        if node in visited:
            continue
        print(f"Iteration {iteration}: Visiting {node}")
        print(f"  g({node}) = {cost}")
        print(f"  h({node}) = {heuristics[node]}")
        print(f"  f({node}) = {est_total}")
        print(f"  Path so far: {' -> '.join(path)}\n")
        iteration += 1

        if node in goal_set:
            print("Goal reached!")
            print("Final Path:", ' -> '.join(path))
            print("Total Cost:", cost)
            return

        visited.add(node)
        for neighbor, edge_cost in graph.get(node, []):
            if neighbor not in visited:
                new_cost = cost + edge_cost
                est = new_cost + heuristics[neighbor]
                heapq.heappush(queue, (est, new_cost, neighbor, path + [neighbor]))

    print("No path found.")

# Input
graph = {}
heuristics = {}
n = int(input("Enter number of nodes: "))
for _ in range(n):
    name = input("Enter node name: ")
    h = int(input(f"Heuristic of {name}: "))
    heuristics[name] = h
    graph[name] = []

e = int(input("Enter number of edges: "))
for _ in range(e):
    u, v, c = input("Enter edge (from to cost): ").split()
    c = int(c)
    graph[u].append((v, c))

start = input("Enter start node: ")
goal_nodes = input("Enter goal nodes (space-separated): ").split()
goal_set = set(goal_nodes)

a_star(graph, heuristics, start, goal_set)

# gpt verify tho
# Enter number of nodes: 5
# Enter node name: A
# Heuristic of A: 6
# Enter node name: B
# Heuristic of B: 4
# Enter node name: C
# Heuristic of C: 2
# Enter node name: D
# Heuristic of D: 0
# Enter node name: E
# Heuristic of E: 5

# Enter number of edges: 6
# Enter edge (from to cost): A B 1
# Enter edge (from to cost): A C 5
# Enter edge (from to cost): B D 5
# Enter edge (from to cost): C D 1
# Enter edge (from to cost): B E 3
# Enter edge (from to cost): E D 1

# Enter start node: A
# Enter goal nodes (space-separated): D
