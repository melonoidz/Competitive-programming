ans=0.0
n=int(input())
if  n==2 :
    print(2.000)
    exit()
ans=pow(n,n-1)/((n-2)*(n-1))
print(ans)