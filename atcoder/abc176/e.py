H, W, M = map(int, input().split())
F = [[0]*(H+1) for i in range(W+1)]
G = [[0]*(W+1) for i in range(H+1)]
for _ in range(M):
    h, w = map(int, input().split())
    h -= 1
    w -= 1
    F[w][h] += 1
    G[h][w] += 1
ans = 0
cnth = []
cntw = []
x = 0
y = 0
for i in range(W):
    cnth.append(sum(F[i]))
    x = max(x, sum(F[i]))
for i in range(H):
    cntw.append(sum(G[i]))
    y = max(y, sum(G[i]))

cx = []
cy = []
for r in range(H):
    if cntw[r] == y:
        cy.append(r)

for l in range(W):
    if cnth[l] == x:
        cx.append(l)

for a in cx:
    for b in cy:
        tmp = cnth[a]+cntw[b]
        if F[a][b] != 0:
            tmp -= 1
        ans = max(ans, tmp)

print(ans)
