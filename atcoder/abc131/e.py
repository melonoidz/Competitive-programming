n, k = map(int, input().split())
ans = []
cot = (n-1)*(n-2)//2
if k > cot:
    print(-1)
    exit()
for i in range(1, n):
    ans.append([i, n])

cnt = cot-k
ci = 1
cj = 2
for i in range(cnt):
    ans.append([ci, cj])
    cj += 1
    if cj == n:
        ci += 1
        cj = ci+1
print(len(ans))
for i, j in ans:
    print(str(i)+" "+str(j))
