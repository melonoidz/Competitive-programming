a, b, c = map(int, input().split())


def su(a):
    return a*(a+1)//2


MOD = 998244353
print(su(a)*su(b)*su(c) % MOD)
