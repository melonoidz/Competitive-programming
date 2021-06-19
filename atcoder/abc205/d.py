import bisect

n,q=map(int,input().split())
a=list(map(int,input().split()))
t=[]
st=0
for i in range(n):
    now=a[i]-st-1
    t.append(now)
    st=a[i]
sn=[]
sn.append(0)
for i in range(len(t)):
    cur=sn[-1]+t[i]
    sn.append(cur)
INF=10**18+10
sn.append(INF)
for i in range(q):
    k=int(input())
    dist=bisect.bisect_left(sn,k)
    if dist==1:
        print(k)
    else:
        res=k-sn[dist-1]
        print(res+a[dist-2])
