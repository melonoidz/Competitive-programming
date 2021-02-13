import math
import decimal
x,y,r=map(float,input().split())
ld=x-r
rd=x+r
left=int(ld)
right=int(rd)
ans=0
for i in range(left,right+1):
    ud=math.sqrt(r**2-(x-i)**2)
    uky=y+ud
    ty=y-ud
