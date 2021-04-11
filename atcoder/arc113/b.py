a,b,c=map(int,input().split())
up=pow(b,c,4)
if up==0:
    up=4
print(pow(a,up,10))