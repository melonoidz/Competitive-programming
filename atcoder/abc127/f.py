import heapq
Q = int(input())

tmp = 0
a = []
lhs = heapq.heapify(a)
rhs = heapq.heapify(a)
for _ in range(Q):
    query = input().split()
    if query[0] == "1":
        a = int(query[1])
        b = int(query[2])
        tmp += b
        if len(lhs)>len(rhs):
