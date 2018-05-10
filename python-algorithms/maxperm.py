def maxperm(l):
    s = set(range(len(l))) - set(l)
    for i in s:
        l[i] = i 
    return l, s == set()

l = [2, 2, 0, 7, 3, 5, 7, 6]
stop = False
while not stop:
    l, stop = maxperm(l)
print(l)
