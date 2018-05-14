import numpy as np

N = 40
K = 15

def maxk(g, k):
    n = g.shape[0]
    degree = g.sum(1)
    kset = set(range(n))
    stop = False
    while not stop:
        stop = True
        for v in kset:
            if degree[v] >= k:
                continue
            kset -= {v}
            for u,uv in enumerate(g[v]):
                degree[u] -= uv
            stop=False
            break
    return kset

g = np.random.randint(0, 2, (N, N), 'int32')
g *= np.tri(N, N, dtype='int32')
g[range(N), range(N)] = 0
g |= g.T

kset = maxk(g, K)
for v in kset:
    s = 0
    for u in range(N):
        if g[v][u] == 1 and u in kset:
            s += 1
    assert(s >= K)
print(len(kset))
