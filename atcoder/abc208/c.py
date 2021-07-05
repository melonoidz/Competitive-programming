n,k=map(int,input().split())
a=[0]*(1000000010)
x=list(map(int,input().split()))
for i in range (n):
    x[i]-=1
    a[x[i]]=i
r=k//n
tmp=k%n
res=[r]*n
if tmp==0:
    for i in range (n):
        print(int(res[i]))
    exit()
sorted(a)
for i in range(1,tmp+1):
    res[a[i]]+=1
for i in range (n):
    print(int(res[i]))