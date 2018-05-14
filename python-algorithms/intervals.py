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

print_nested_on2(intervals)
