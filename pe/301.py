ans=0
for i in range(1+4):
    if(i^(2*i)^(3*i)==0):
        ans+=1
print(ans)

# ans[1]=2
# ans[2]=3
# ans[4]=4
# ans[8]=6
# ans[16]=9//<=2^4
# ans[32]=14
# ans[64]=22
dp=[0]*(40)
dp[0]=2
dp[1]=3
for i in range(2,35):
    dp[i]=(dp[i-1]+dp[i-2])-1

print(dp[30])
#AC 0の場合を引く