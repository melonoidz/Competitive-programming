
def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 10**9+7 #出力の制限
N = 10**6+10
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

n=int(input())
MOD=10**9+7
if n==1:
    print(0)
    exit()
elif n==2:
    print(2)
    exit()


ans=pow(10,n,MOD)-pow(8,n,MOD)
ans%=MOD
tmp=0
for i in range(0,n):
    cnt=pow(8,i,MOD)*cmb(n,i,MOD)
    ans-=cnt*2
    ans%=MOD
print(ans)

