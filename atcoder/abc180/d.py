
import math
x, y, a, b = map(int, input().split())
ans = 0
while x*a < y and (a-1)*x <= b:
    x *= a
    ans += 1

print(ans+(y-1-x)//b)
