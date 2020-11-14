from copy import deepcopy
h, w = map(int, input().split())
f = [input() for i in range(h)]
ans = 0
MOD = 1000000007
wl = [[0]*w for i in range(h)]
wr = [[0]*w for i in range(h)]
hl = [[0]*w for i in range(h)]
hr = [[0]*w for i in range(h)]

for i in range(h):
    if f[i][0] == ".":
        wl[i][0] = 1
    for j in range(1, w):
        if f[i][j] == ".":
            wl[i][j] = wl[i][j-1]+1
        else:
            continue
frev = deepcopy(f[::-1])
for i in range(h):
    if frev[i][0] == ".":
        wr[i][0] = 1
    for j in range(1, w):
        if frev[i][j] == ".":
            wr[i][j] = wr[i][j-1]+1
        else:
            continue

fiv = deepcopy(f)
fir = deepcopy(f)

for i in range(w):
    if fiv[0][i] == ".":
        hl[0][i] = 1
    for j in range(1, h):
        if fiv[j][i] == ".":
            hl[j][i] = hl[j-1][i]+1
        else:
            continue

for i in range(w):
    if fir[h-1][i] == ".":
        hr[h-1][i] = 1
    for j in range(h-2, -1, -1):
        if fir[j][i] == ".":
            hr[j][i] = hr[j+1][i]+1
        else:
            continue

allcnt = 0
for i in range(h):
    for j in range(w):
        if f[i][j] == ".":
            allcnt += 1

for i in range(h):
    for j in range(w):
        if f[i][j] == ".":
            tmp = 0
            ans += pow(2, allcnt, MOD)*pow(2, tmp, MOD)
            ans %= MOD

print(hl)
print(hr)
print(wl)
print(wr)

#print(ans % MOD)
