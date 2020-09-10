def digit(a):
    ans=0
    aa=str(a)
    for i in range(len(aa)):
        ans+=(int)(aa[i])
    return ans
ans=0
for i in range(1,100):
    for j in range(1,100):
        tmp=digit(i**j)
        ans=max(ans,tmp)

print(ans)