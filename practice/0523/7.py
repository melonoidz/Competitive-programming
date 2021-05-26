n,k=map(int,input().split())
x=0
for i in range(3, 3*n+1):
    cnt=(i-1)*(i-2)//2
    if k-cnt>0:
        k-=cnt
    else:
        x=i
        break
p=0
q=0
r=0
print(x,k,i)
for i in range(1,n+1):
    now=0
    if x-i>2*n:
        now=0
    else:
        now=max(n,x-i-n)-min(n,x-i-n)+1
    
    if k-now>0:
        k-=now
    else:
        p=i
        break
if x-p<=n+1:
    q=k
else:
    q=x-p-n+(k-1)
r=x-p-q
print(p,q,r)