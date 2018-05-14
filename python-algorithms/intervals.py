intervals = [
    (10, 15),
    (5, 8),
    (1, 6),
    (7, 9),
    (11, 14),
    (2, 4),
    (0, 3),
    (12, 13),
]

intervals.sort(key = lambda x: x[0])

def print_nested_on2(intervals, printed_set=set()):
    if (len(intervals) <= 1):
        return
    s0, e0 = intervals[0]
    for s, e in intervals[1:]:
        if s > e0:
            break
        if e < e0 and s not in printed_set:
            print(s, e)
            printed_set.add(s)
    print_nested_on2(intervals[1:], printed_set)

print("O(n^2)")
print_nested_on2(intervals)

max_ends = [0] * len(intervals)
m = -1
for i in range(len(intervals)):
    if intervals[i][1] > m:
        m = intervals[i][1]
    max_ends[i] = m

def print_nested_on(intervals, i):
    if (i == 0):
        return
    print_nested_on(intervals, i-1)
    if intervals[i][1] < max_ends[i-1]:
        print(intervals[i])

print("O(n)")
print_nested_on(intervals, len(intervals)-1)
