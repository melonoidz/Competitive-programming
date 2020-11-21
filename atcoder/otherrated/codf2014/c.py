def num(A):
    A = str(A)
    res = 0
    l = len(A)
    B = A[:]
    A = A[::-1]
    for i in range(l):
        if i == 0:
            res += int(A[0])
        else:
            res += int(A[i])*pow(int(B), i)
    return res


cnt = []
for i in range(1, 10001):
    cnt.append(num(i))
a = int(input())
for i in range(len(cnt)):
    if cnt[i] == a:
        if a < 10:
            continue
        print(i+1)
        exit()
print(-1)
