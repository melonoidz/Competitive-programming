# 階段状になる
# 全体から斜めを引いて半分にする　
N,p=map(int,input().split())
MOD=1000000007
# sigma(i:1~N) ,sigma(j:1~i) Ai*Aj

A=[0]*(N+1)
A[1]=0
A[2]=1
for i in range(3,N+1):
    A[i]=p*A[i-1]+A[i-2]
    A[i]%=MOD
