N, M = map(int, input().split())
g = [[] for i in range(N)]
for i in range(M):
    A, B = map(int, input().split())
    g[A - 1].append(B - 1)
    g[B - 1].append(A - 1)

visited = [False for i in range(N)]

def visit(v, s):
    visited[v] = True
    s.append(v)
    for w in g[v]:
        if not visited[w]:
            visit(w, s)

def paint(p, c, s):
    v = s[p]
    for w in g[v]:
        if c[w] == c[v]:
            return 0
    if p == len(s) - 1:
        return 1
    ret = 0
    for i in range(3):
        c[s[p + 1]] = i
        ret += paint(p + 1, c, s)
    c[s[p + 1]] = -1
    return ret

ans = 1
for i in range(N):
    if not visited[i]:
        s = []
        visit(i, s)
        c = [0 if j == i else -1 for j in range(N)]
        ans *= paint(0, c, s) * 3
print(ans)