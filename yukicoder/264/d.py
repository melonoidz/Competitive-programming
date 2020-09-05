q=int(input())

def modinv(a, mod=10**9+7):
    return pow(a, mod-2, mod)

def Comb(n, r, mod=10**9+7):
    r = min(r, n-r)
    res = 1
    for i in range(r):
        res = res * (n - i) * modinv(i+1, mod) % mod
    return res

for i in range(q):
    n,m,k=map(int,input().split())
    f=Comb(n,k)*m
    s=pow(m,k)*max(0, n-k+1)
    if f>s:
        print("Straight")
    else:
        print("Flush")
#対数を取ると良いらしい，たしかに．．．(計算式はあっていた)