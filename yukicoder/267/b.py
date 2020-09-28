import math

n=int(input())
a=list(map(int,input().split()))
if 0 in a:
    print(-1)
    exit()
MOD=10**9+7
fra=[]
if (max(a)>=4):
    print(MOD)
    exit()
for j in a:
    fra.append(math.factorial(j))
ans=1

for i in range(n):
    ans*=(a[i]**fra[i])

print(MOD%ans)