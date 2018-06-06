# https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

from random import randint

L = [randint(1, 100) for _ in range(1000)]
S = sum(L[555:888])

def find_sub():
    s = L[0]
    si = ei = 0

    while s != S:
        if s < S:
            if ei >= len(L)-1:
                return (-1, -1)
            ei += 1
            s += L[ei]
        else:
            if si >= len(L)-1:
                return (-1, -1)
            s -= L[si]
            si += 1
            if ei < si:
                ei += 1
                s += L[ei]

    if s == S:
        return (si, ei)
    else:
        return (-1, -1)

idx = find_sub()
print(idx)
if idx[0] != -1:
    assert S == sum(L[idx[0]:idx[1]+1])
