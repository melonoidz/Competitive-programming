from collections import deque
from bisect import bisect_left
n = int(input())
A = list(int(input()) for i in range(n))
x = deque([])

for a in A:
    i = bisect_left(x, a)
    if i == 0:
        x.appendleft(a)
    else:
        x[i-1] = a

print(len(x))
