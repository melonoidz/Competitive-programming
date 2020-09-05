n,z=map(int,input().split())

for i in range(1,z):
    for j in range(i,z+1):
        if i**n+j**n==z**n:
            print("Yes")
            exit()

print("No")