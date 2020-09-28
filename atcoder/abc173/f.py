n = int(input())
V = 0
E = 0
for i in range(n-1):
    u, v = map(int, input().split())
    if u > v:
        u, v = v, u
    E += u*(n-v+1)

for i in range(n-1):
    V += (i+1)*(n-i)
print(V-E+n)

# https://blog.bobuhiro11.net/2020/07-07-abc173f.html
