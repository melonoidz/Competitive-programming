import math
n = int(input())
X = list(map(int, input().split()))
m = 0
y = 0
c = 0
D = []
for x in X:
    m += abs(x)
    y += x**2
    D.append(abs(x))

c = max(D)
print(m)
print(math.sqrt(y))
print(c)
