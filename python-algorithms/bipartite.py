G1 = (
    (1, 4, 5),
    (0, 3),
    (1, 5),
    (1, 4),
    (0, 3),
    (0, 2),
)

G2 = (
    (1, 4, 5),
    (0, 3),
    (1, 5),
    (0, 1, 4),
    (0, 3),
    (0, 2),
)

def is_bipartite(g):
    color = [0] * len(g)
    q = [0]
    color[0] = 1
    while q:
        u = q.pop()
        for v in g[u]:
            if color[v] == color[u]:
                return 'Not bipartitie'
            if color[v] == 0:
                color[v] = -color[u]
                q.append(v)
    return 'Bipartite'

print(is_bipartite(G1))
print(is_bipartite(G2))
