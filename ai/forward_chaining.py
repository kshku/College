initial_state = ['dirty', 'smelly']
goal_state = ['fresh']

rules = [
    {'if': ['dirty'], 'then': ['clean']},
    {'if': ['clean', 'smelly'], 'then': ['fresh']},
]

current_state = initial_state

while not all(x in current_state for x in goal_state):
    for rule in rules:
        if all(x in current_state for x in rule['if']):
            current_state += rule['then']

print(f"Final state: {current_state}")
