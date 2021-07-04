l,r=map(int,input().split())
mod=10**9+7
ans=0
def f(x):
    res=(x*(x+1)//2)%mod
    return res

for i in range(1,20):
    vl=max(l,10**(i-1))
    vr=min(r,10**i-1)
    if vl>vr :
        continue
    val=f(vr)-f(vl-1)
    ans+=val*i
    ans%=mod

print(ans%mod)