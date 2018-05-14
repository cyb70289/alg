G = {
    'a': { 'b', 'f' },
    'b': { 'c', 'd', 'f' },
    'c': { 'd' },
    'd': { 'e', 'f' },
    'e': { 'f' },
    'f': set(),
};


def tsort_naive(g):
    while g:
        s = set(g.keys())
        for _, v in g.items():
            s -= v
        for i in s:
            print(i)
            del(g[i])


tsort_naive(G)
