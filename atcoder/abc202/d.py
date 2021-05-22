import math 
a,b,k=map(int,input().split())
ans=""
while 1<a+b:
    tmp=math.factorial(a+b-1)
    if a<2:
        na=1
    else: 
        na=math.factorial(a-1)
    if b<1:
        nb=1
    else: 
        nb=math.factorial(b)
    tmp//=na
    tmp//=nb
        
    if k<=tmp:
        ans+="a"
        a-=1
    else:
        ans+="b"
        b-=1
        k-=tmp

while a>0:
    ans+="a"
    a-=1
while b>0:
    ans+="b"
    b-=1

print(ans)