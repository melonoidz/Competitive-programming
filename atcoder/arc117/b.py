n=int(input())
a=list(map(int,input().split()))
a.sort()
MOD=10**9+7
ans=a[0]+1
ans%=MOD
for i in range(n-1):
    diff=a[i+1]-a[i]+1
    ans*=diff
    ans%=MOD
print(ans)
