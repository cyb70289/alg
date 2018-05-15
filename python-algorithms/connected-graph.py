G = (
    (1, 3),
    (0,),
    (3, 5),
    (0, 2),
    (5,),
    (2, 4),
)

def print_v(g):
    q = [0]
    printed = set()
    while q:
        v = q.pop()
        print(v)
        printed.add(v)
        for u in g[v]:
            if u not in printed:
                q.append(u)

print_v(G)
