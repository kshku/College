# Not completed
def negate(l):
    return l[1:] if l[0] == '~' else '~' + l

def resolve(c1, c2):
    new_clause = []
    for l in c1:
        if negate(l) not in c2:
            new_clause.append(l)
    for l in c2:
        if negate(l) not in c1:
            new_clause.append(l)

    return new_clause

def resolution(KB, q):
    kb = KB.copy()
    kb.append([negate(q)])
