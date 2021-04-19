def judge(a,m,sx):
    tmp=0
    cnt=1
    for i in range(len(sx)-1, -1,-1):
        tmp+=int(sx[i])*cnt
        cnt*=a
    if tmp<=m:
        return True
    return False



x=input()
m=int(input())
if len(x)==1:
    if int(x)>m:
        print(0)
    else :
        print(1)
    exit()
st=0
for u in x:
    st=max(st,int(u))
ok=st
ng=10**18+1
while abs(ok-ng)>1:
    mid=(ok+ng)//2
    if judge(mid,m,x):
        ok=mid
    else:
        ng=mid
print(ng-st-1)