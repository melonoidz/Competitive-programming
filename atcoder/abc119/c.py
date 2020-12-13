import builtins
import itertools

n, a, b, c = map(int, input().split())
l = [int(input()) for i in range(n)]
ans = 10**10
for bit in itertools.product([0, 1, 2, 3], repeat=n):
    na = [0]*3
    now = list(bit)
    cost = 0
    for i in range(n):
        if now[i] != 3:
            if na[now[i]] != 0:
                cost += 10
            na[now[i]] += l[i]
    if 0 in na:
        continue
    cost += abs(a-na[0])
    cost += abs(b-na[1])
    cost += abs(c-na[2])
    ans = min(ans, cost)

print(ans)
