p=[0]*2020

p[0]=2
p[1]=3
for i in range(2,1001):
    p[(i-1)*2]=p[(i-1)*2-2]+p[(i-1)*2-1]
    p[(i-1)*2+1]=p[(i-1)*2]+p[(i-1)*2-2]
ans=0
for i in range(1,1001):
    a=str(p[(i-1)*2])
    b=str(p[(i-1)*2+1])
    if len(a)<len(b):
        ans+=1

print(ans)