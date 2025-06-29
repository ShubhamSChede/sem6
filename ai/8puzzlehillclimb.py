import copy

goal_state = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]  
]

initial_state = [
    [1, 2, 3],
    [0, 4, 6],
    [7, 5, 8]
]

moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return (i, j)
    return None

def misplaced_tiles(state):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != goal_state[i][j]:
                count += 1
    return count

def get_neighbors(state):
    neighbors = []
    x, y = find_blank(state)

    for dx, dy in moves:
        new_x, new_y = x + dx, y + dy
        if 0 <= new_x < 3 and 0 <= new_y < 3:
            new_state = copy.deepcopy(state)
            new_state[x][y], new_state[new_x][new_y] = new_state[new_x][new_y], new_state[x][y]
            neighbors.append(new_state)
    return neighbors

def hill_climbing(start):
    current = start
    current_h = misplaced_tiles(current)
    path = [current]

    while True:
        neighbors = get_neighbors(current)
        next_state = None
        next_h = current_h

        for neighbor in neighbors:
            h = misplaced_tiles(neighbor)
            if h < next_h:
                next_state = neighbor
                next_h = h

        if next_state is None:
            print("Stuck at local minimum.")
            break

        current = next_state
        current_h = next_h
        path.append(current)

        if current_h == 0:
            print("Goal reached!")
            break

    print("Path:")
    for step in path:
        for row in step:
            print(row)
        print("---")

hill_climbing(initial_state)


