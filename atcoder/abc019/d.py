import sys
n = int(input())
s = 1
u = 0
ma = 0
for i in range(1, n+1):
    if s != i:
        print("? {0} {1}".format(s, i))
        sys.stdout.flush()
        dist = int(input())
        if ma < dist:
            ma = dist
            u = i
ans = 0
for i in range(1, n+1):
    if u != i:
        print("? {0} {1}".format(u, i))
        sys.stdout.flush()
        dist = int(input())
        if ans < dist:
            ans = dist

print("! "+str(ans))
