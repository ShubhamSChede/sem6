import random

def print_board(state):
    n = len(state)
    for row in range(n):
        line = ""
        for col in range(n):
            line += "Q " if state[row] == col else ". "
        print(line)
    print()

def count_attacks(state):
    attacks = 0
    n = len(state)
    for i in range(n):
        for j in range(i+1, n):
            if state[i] == state[j] or abs(state[i] - state[j]) == abs(i - j):
                attacks += 1
    return attacks

def get_best_neighbor(state):
    n = len(state)
    best = state[:]
    min_attacks = count_attacks(state)

    for row in range(n):
        for col in range(n):
            if col != state[row]:
                new_state = state[:]
                new_state[row] = col
                attacks = count_attacks(new_state)
                if attacks < min_attacks:
                    min_attacks = attacks
                    best = new_state
    return best, min_attacks

def hill_climbing(n):
    current = [random.randint(0, n-1) for _ in range(n)]
    current_attacks = count_attacks(current)

    while True:
        next_state, next_attacks = get_best_neighbor(current)
        if next_attacks >= current_attacks:
            return current  # Local optimum or solution
        current = next_state
        current_attacks = next_attacks

# --- Main ---
n = int(input("Enter number of queens (N): "))
solution = hill_climbing(n)
print("\nSolution:")
print_board(solution)