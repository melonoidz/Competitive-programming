n=int(input())
ans=0
for l in range(0,10**6+1):
    if (2*n)%(l+1)==0:
        tmp=2*n//(l+1)
        if (tmp-l)%2==0:
            ans+=1
print(ans)