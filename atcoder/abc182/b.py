
n = int(input())
A = list(map(int, input().split()))
ans = 0
tmp = 0
for i in range(2, 1001):
    cnt = 0
    for a in A:
        if a % i == 0:
            cnt += 1
    if tmp < cnt:
        ans = i
        tmp = cnt

print(ans)
