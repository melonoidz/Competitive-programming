S = input().split(" ")
n = int(input())
if n == 0:
    print(*S)
    exit()
t = []
ans = []
for i in range(n):
    w = input()
    t.append(w)
for s in S:
    result = ""
    for r in t:
        flag = True
        if len(s) != len(r):
            flag = False
        else:
            for i in range(len(r)):
                if s[i] == r[i] or r[i] == "*":
                    continue
                else:
                    flag = False
                    break
        if flag:
            result = "*"*len(s)
            break
        else:
            result = s
    ans.append(result)

print(*ans)
