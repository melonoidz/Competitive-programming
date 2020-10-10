h, w = map(int, input().split())
S = [input() for i in range(h)]
ans = 0
for s in S:
    for i in range(len(s)-1):
        if s[i] == s[i+1] and s[i] == ".":
            ans += 1
for i in range(w):
    for j in range(h-1):
        if S[j][i] == S[j+1][i] and S[j][i] == ".":
            ans += 1

print(ans)
