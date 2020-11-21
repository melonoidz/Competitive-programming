S=input().split(" ")
n=int(input())
t=[]
ans=[]
for i in range(n):
    w=input()
    t.append(w)
for s in S:
    for r in t:
        flag=True
        if len(s)!=len(r):
            continue
        for i in range(len(r)):
            if s[i]==r[i] or r[i]=="*":
                
