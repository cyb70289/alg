G = (
    ( 5, ),
    ( 2, 5 ),
    ( 3, 4 ),
    ( 1, 4 ),
    (),
    ( 6, ),
    ( 0, ),
)

def dfs1(g, u, time, color, start, end):
    color[u] = 1
    start[u] = time
    time += 1
    for v in g[u]:
        if color[v] == 0:
            time = dfs1(g, v, time, color, start, end)
    color[u] = 2
    end[u] = time
    print(u, (start[u], end[u]))
    return time+1

def dfs(g):
    color = [0] * len(g)
    start = [0] * len(g)
    end = [0] * len(g)
    time = 1
    for u in range(len(g)):
        if color[u] == 0:
            time = dfs1(g, u, time, color, start, end)

def bfs1(g, u, visited):
    q = [u]
    while q:
        v = q.pop()
        visited[v] = 1
        print(v)
        for vv in g[v]:
            if not visited[vv]:
                q.append(vv)

def bfs(g):
    visited = [0] * len(g)
    for u in range(len(g)):
        if visited[u] == 0:
            bfs1(g, u, visited)

dfs(G)
bfs(G)
