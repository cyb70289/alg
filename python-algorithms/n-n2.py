import random

N = 100

V = [random.randint(0, N*N-1) for _ in range(N)]

def cnt_sort(v, vk, n):
    vout = [-1] * len(v)
    vk_cnt = [0] * n
    for i in vk:
        vk_cnt[i] += 1
    total = 0
    for i in range(len(vk_cnt)):
        t = vk_cnt[i]
        vk_cnt[i] = total
        total += t
    for i in range(len(v)):
        vout[vk_cnt[vk[i]]] = v[i]
        vk_cnt[vk[i]] += 1
    return vout

v0 = [i % N for i in V]
v = cnt_sort(V, v0, N)
v1 = [i // N for i in v]
v = cnt_sort(v, v1, N)
print(v)

for i in range(len(v)-1):
    assert(v[i+1] >= v[i])
