n, k = map(int, input().split())
a = list(map(int, input().split()))
MOD = 10**9+7
minus = []
plus = []
an = []
for x in a:
    if x < 0:
        minus.append(x)
    else:
        plus.append(x)
    an.append(abs(x))

if n == k:
    ans = 1
    for i in a:
        ans *= i
        ans %= MOD
    print(ans)
    exit()

if len(minus) == n:
    ans = 1
    if k % 2 != 0:
        minus.sort(reverse=True)
        for i in range(k):
            ans *= minus[i] % MOD
        print(ans)
    else:
        minus.sort()
        for i in range(k):
            ans *= minus[i] % MOD
        print(ans)
    exit()

if k % 2 != 0:
