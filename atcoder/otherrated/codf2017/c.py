s = input()
cnt = 0
flag = True
for i in range(len(s)//2):
    if s[i] != s[len(s)-1-i]:
        flag = False
        break
if flag:
    print(0)
    exit()
l=len(s)
for i in range((l-2)//2):
    if s[i]=="x" and s[l-1-i]!="x":
