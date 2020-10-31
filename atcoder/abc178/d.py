S = int(input())
q1 = [1, 1]
q2 = [1, 1]
inverse = [0, 1]
n = 10**6
ans = 0


def cmb(n, r, p):
    if (r < 0) or (n < r):
        return 0
    r = min(r, n - r)
    return fact[n] * factinv[r] * factinv[n-r] % p


p = 10 ** 9 + 7
N = 10 ** 5  # N は必要分だけ用意する
fact = [1, 1]
factinv = [1, 1]
inv = [0, 1]

for i in range(2, N + 1):
    fact.append((fact[-1] * i) % p)
    inv.append((-inv[p % i] * (p // i)) % p)
    factinv.append((factinv[-1] * inv[-1]) % p)
ans = 0

for i in range(1, S//3+1):
    k = S-3*i
    if k < 0:
        print(ans % p)
        exit()
    ans += cmb(k+i-1, i-1, p)
    ans %= p
print(ans)
