n = int(input())
r = list(map(int, input().split()))
rn = []
i = 0
while i < n:
    rn.append(r[i])
    tmp = i
    while r[tmp] == r[i]:
        i += 1
        if i >= n:
            break
n = len(rn)
if n <= 2:
    print(0)
    exit()
c = (rn[0] < rn[1])
ans = 2
for i in range(1, n-1):
    if (rn[i] < rn[i+1]) != c:
        ans += 1
        c = (rn[i] < rn[i+1])
print(ans if ans >= 3 else 0)