import itertools
n=int(input())
a=list(map(int,input().split()))
ans=1e9
for i in range(1,n+1):
    num=[]
    for j in range(1,i+1):
        num.append(j)
    for div in itertools.combinations_with_replacement(num,n):
        tmp=list(div)
        now=a[0]
        cur=[]
        cnt=tmp[0]
        for k in range(1,n):
            if tmp[k]==cnt:
                now|= a[k]
            else :
                cur.append(now)
                cnt=tmp[k]
                now=a[k]
        cur.append(now)
        res=cur[0]
        if len(cur)>1 :
            for dx in range (1, len(cur)):
                res^=cur[dx]
        ans=min(ans,res)
print(ans) 
