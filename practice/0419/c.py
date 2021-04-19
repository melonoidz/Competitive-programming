a,b,c=map(int,input().split())
tmp=pow(b,c,4)
if tmp==0:
    tmp+=4
print(pow(a,tmp,10))