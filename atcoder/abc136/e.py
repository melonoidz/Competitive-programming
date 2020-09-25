n,k=map(int,input().split())
A=list(map(int,input().split()))
g=sum(A)

div=[]
i=1
while i*i<=g:
    if g%i==0:
        div.append(i)
        if not (i==g//i):
            div.append(g//i)
    i+=1

div.sort()

for x in div:
    res=0
    for a in A:
        res+=a-x
    