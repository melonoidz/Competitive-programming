a,b=map(int,input().split())
c=pow(a,b,10**9+7)
d=pow(b,a,10**9+7)
if c==d:
    print("Yes")
else:
    print("No")
