n,k=map(int,input().split())
mod=10**9+7
print((pow(n,k+1,mod)-n*pow(n-1,k,mod))%mod)