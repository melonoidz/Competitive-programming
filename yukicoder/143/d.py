a,b,c = map(int,input().split("^"))
MOD=10**9+7
p=pow(a,b,MOD)
q=pow(b,c,MOD-1)
print(str(pow(p,c,MOD))+" "+str(pow(a,q,MOD)))