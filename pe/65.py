#  e=[2; (0),1,2|1,1,4|1,1,6|1,1,8|1,1,10|1,…]
# 100項目は100/3=33・・・1
# 1,1,64|{1}
# (分子)*(2k)+(前の分子)
# (分母)*(2k)+(前の分母)

def cal(a):
    v=str(a)
    ans=0
    for i in v:
        ans+=int(i)
    return ans

child=[0]*200
mother=[0]*200
child[0]=2
child[1]=3
mother[0]=1
mother[1]=1
child[2]=8
mother[2]=3
cnt=2
for i in range(3,120):
    if i%3==2:
        cnt+=2
        child[i]=cnt*child[i-1]+child[i-2]
        mother[i]=cnt*mother[i-1]+mother[i-2]
    else:
        child[i]=child[i-1]+child[i-2]
        mother[i]=mother[i-1]+mother[i-2]

print(cal(child[99]))
#AC
