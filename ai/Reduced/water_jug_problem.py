visited = set()

def water_jug_solve(j1_cap, j2_cap, j1, j2, target):
    if (j1, j2) in visited:
        return False

    visited.add((j1, j2))

    if target in (j1, j2):
        print("Target reached!")
        return True

    j1_empty = j1_cap - j1
    j2_empty = j2_cap - j2

    operations = (
        (j1_cap, j2), # Fill j1
        (j1, j2_cap), # Fill j2
        (0, j2), # Empty j1
        (j1, 0), # Empty j2
        (j1 - min(j1, j2_empty), j2 + min(j1, j2_empty)), # Pour j1 to j2
        (j1 + min(j2, j1_empty), j2 - min(j2, j1_empty)), # Pour j2 to j1
    )

    for op in operations:
        if water_jug_solve(j1_cap, j2_cap, op[0], op[1], target):
            print(f"Operation: {op}")
            return True

    return False

if not water_jug_solve(4, 3, 0, 0, 2):
    print("Cannot solve!")
else:
    print("Solved!")
