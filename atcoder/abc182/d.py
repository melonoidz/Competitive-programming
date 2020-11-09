import numpy as np
N = int(input())
A = list(map(int, input().split()))
v = []
ans=0
tmp=0
pl=0
for i in range(N):
    v.append(sum(A[:i+1]))
    pl=max(pl,v[-1])
    tmp=max(ans,ans+pl)
    ans=max(ans,ans+v[-1])
print(tmp)


