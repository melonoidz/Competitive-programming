b,c=map(int,input().split())
if c==1:
    if b==0:
        print(1)
    else:
        print(2)
    exit()

l1=b-c//2
r1=b+(c-2)//2
l2=-b-(c-1)//2
r2=-b+(c-1)//2
if r1<l2 or r2<l1:
    ans=(r1-l1+1)+(r2-l2+1)
    print(ans)
else:
    ans=max(r1,r2)-min(l1,l2)+1
    print(ans)