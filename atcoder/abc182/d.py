import numpy as np
N = int(input())
A = list(map(int, input().split()))
v = []
di = 0
ans = 0
tmp = 0
dist = 0
di = np.cumsum(A)
for i in range(N):
    v.append(di[i])
    tmp += di[i]
    if i < N-1:
        dist = max(dist, di[i])
        ans = max(ans, tmp+dist)
    if i == N-1:
        ans = max(ans, tmp)
print(ans)
