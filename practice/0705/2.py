a,b,c=map(int,input().split())
k=int(input())
mod=10**9+7
nmod=mod-1
ans=(a*b*c)%mod
cur=pow(2,k,nmod)
print(pow(ans,cur,mod))