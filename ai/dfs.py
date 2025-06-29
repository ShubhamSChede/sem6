from collections import deque

def dfs(adjacency_list, start):
    visited = set()
    stack = [start]
    traversal = []
    while stack:
        node = stack.pop()
        if node not in visited:
            traversal.append(node)
            visited.add(node)
            stack.extend(reversed(adjacency_list.get(node, [])))
    return traversal

def shortest_path(adjacency_list, start, goal):
    queue = deque([(start, [start])])
    visited = set()

    while queue:
        node, path = queue.popleft()
        if node == goal:
            return path
        if node not in visited:
            visited.add(node)
            for neighbor in adjacency_list.get(node, []):
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))
    return []

def main():
    n = int(input("Number of nodes: "))
    adjacency_list = {}

    print("Enter each node followed by its neighbors(space-separated):")
    for _ in range(n):
        parts = input("> ").split()
        node = parts[0]
        neighbors = parts[1:]
        adjacency_list[node] = neighbors

    start = input("Start node: ")
    goal = input("Goal node: ")

    print("DFS:", dfs(adjacency_list, start))

    path = shortest_path(adjacency_list, start, goal)
    print(path)

if __name__ == "__main__":
    main()
