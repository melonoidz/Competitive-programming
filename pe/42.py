from collections import defaultdict
d=defaultdict(int)
alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
f=open('/home/melonoidz/kyop/pe/word.txt','r')
text=f.read()
words=text.split(",")
ml=0
for w in words:
    now=0
    for moji in w:
        now+=(alp.find(moji)+1)
    d[now]+=1
    ml=max(ml,now)
ans=0
for i in range(1,ml+1):
    now=i*(i+1)//2
    ans+=d[now]
    if now>ml:
        break
print(ans)

