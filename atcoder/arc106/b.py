from collections import defaultdict


class UnionFind:
    def __init__(self, n):
        self.table = [-1] * n

    def _root(self, x):
        stack = []
        tbl = self.table
        while tbl[x] >= 0:
            stack.append(x)
            x = tbl[x]
        for y in stack:
            tbl[y] = x
        return x

    def find(self, x, y):
        return self._root(x) == self._root(y)

    def unite(self, x, y):
        r1 = self._root(x)
        r2 = self._root(y)
        if r1 == r2:
            return
        d1 = self.table[r1]
        d2 = self.table[r2]
        if d1 <= d2:
            self.table[r2] = r1
            self.table[r1] += d2
        else:
            self.table[r1] = r2
            self.table[r2] += d1

    def get_size(self, x):
        return -self.table[self._root(x)]


check = defaultdict(int)
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
uf = UnionFind(n)
graph = [[0] for i in range(n)]
for i in range(m):
    c, d = map(int, input().split())
    c -= 1
    d -= 1
    uf.unite(c, d)
for i in range(n):
    y = uf._root(i)
    check[y] += a[i]
    check[y] -= b[i]
for k in check.values():
    if k != 0:
        print("No")
        exit()
print("Yes")
