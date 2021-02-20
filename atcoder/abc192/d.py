
def ch(a,x):
    tmp=0
    f=1
    l=len(x)
    for i in range(l):
        num=int(x[l-i-1])
        if i==0:
            tmp+=num
        else:
            tmp+=(num*f)
        f*=a
    return tmp


x=input()
m=int(input())
l=len(x)
if l==1:
    if int(x)>m:
        print(0)
    else:
        print(1)
    exit()
g=0
for i in range(l):
    g=max(g,int(x[i]))

bottom=g
top=10**18+1
while top-bottom>1:
    mid=(top+bottom)//2
    if ch(mid,x)<=m:
        bottom=mid
    else :
        top=mid

print(top-g-1)

