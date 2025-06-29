from collections import deque

def bfs_with_path(graph, start, goal):
    queue = deque([start])
    visited = set([start])
    parents = {start: None}

    while queue:
        current = queue.popleft()
        print(current, end=" ")

        if current == goal:
            break

        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                visited.add(neighbor)
                parents[neighbor] = current
                queue.append(neighbor)

    # Build path
    path = []
    if goal in visited:
        while goal:
            path.append(goal)
            goal = parents[goal]
        path.reverse()
        return path
    else:
        return None

def main():
    n = int(input("Number of nodes: "))
    graph = {}
    print("Enter each node followed by its neighbors (space-separated):")
    for _ in range(n):
        parts = input("> ").split()
        node = parts[0]
        neighbors = parts[1:]
        graph[node] = neighbors

    start = input("Start node: ")
    goal = input("Goal node: ")

    print("BFS:", end=" ")
    path = bfs_with_path(graph, start, goal)

    if path:
        print(path)
    else:
        print("\nNo path found")

if __name__ == "__main__":
    main()



















