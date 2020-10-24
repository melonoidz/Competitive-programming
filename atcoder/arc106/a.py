n=int(input())
for b in range(1,30):
    for a in range(1,60):
        if (3**a)+(5**b)==n:
            print(str(a)+" "+str(b))
            exit()
print(-1)
