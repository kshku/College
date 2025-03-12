initial_state = ['fresh']
goal_state = ['dirty', 'smelly']

rules = [
   {'if': ['dirty'], 'then': ['clean']},
   {'if': ['clean', 'smelly'], 'then': ['fresh']},
]

current_state = initial_state

while not all(state in current_state for state in goal_state):
    for rule in reversed(rules):
        if all(state in current_state for state in  rule['then']):
            current_state += rule['if']

print(f"Final state: {current_state}")
