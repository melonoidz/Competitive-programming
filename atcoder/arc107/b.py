n, k = map(int, input().split())
# (a+b)=K+(c+d), 2<=a+b<=2N
ans = 0
for i in range(2, 2*n+1):
    if 2 <= i+k <= 2*n:
        i -= 2
        ans += (n-1-max(0, i-(n-1))+1)*(n-1-max(0, i+k-(n-1))+1)
print(ans)
