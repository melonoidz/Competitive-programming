s = input()
k = int(input())
al = "abcdefghijklmnopqrstuvwxyz"
for i in range(len(s)):
    if s[i]!="a" and 27-al.find(s[i])<=k:
        cnt=al.find(s[i])
        s[i].replace(s[i], "a")
        k-=(27-cnt)
    if i==len(s)-1:
        k%=26
        cz=al.find(s[i])
        if 27-cz<k:
            s[i].replace(s[i], al[k-(27-cz)])
        else :
            s[i].replace(s[i], al[cz+k])

print(s)

