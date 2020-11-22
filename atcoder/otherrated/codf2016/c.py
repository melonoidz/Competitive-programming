s = input()
k = int(input())
al = "abcdefghijklmnopqrstuvwxyz"
ans = ""
for i in range(len(s)):
    cnt = al.find(s[i])
    if cnt == 0 and i != len(s)-1:
        ans += "a"
    elif k >= 26-cnt:
        ans += "a"
        k -= (26-cnt)
    else:
        k %= 26
        if i == len(s)-1:
            now = al.find(s[i])
            ans += al[(now+k) % 26]
        else:
            ans += s[i]
print(ans)
