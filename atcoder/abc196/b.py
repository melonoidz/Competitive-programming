x=str(input())

ans=""
for i in x:
    if i==".":
        print(ans)
        exit()
    ans+=i
print(x)
    
