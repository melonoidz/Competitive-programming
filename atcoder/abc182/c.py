def solve(n):
    cnt = [0]*3
    for a in n:
        tmp = ord(a)-ord('0')
        cnt[tmp % 3] += 1
    s = cnt[1]*1+cnt[2]*2
    s %= 3
    if s == 0:
        return 0
    elif s == 1:
        if cnt[1] >= 1:
            return 1
        elif cnt[2] >= 2:
            return 2
        else:
            return -1
    elif s == 2:
        if cnt[2] >= 1:
            return 1
        elif cnt[1] >= 2:
            return 2
        else:
            return -1


n = input()
y = solve(n)
if len(n) == y:
    print(-1)
else:
    print(y)
