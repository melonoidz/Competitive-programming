import numpy as np

a=[[0,-1,0],[1,0,0],[0,0,1]]
b=[[0,1,0],[-1,0,0],[0,0,1]]

def getc(p):
    c=[[-1,0,2*p],[0,1,0],[0,0,1]]
    return c

def getd(p):
    d=[[-1,0,0],[0,1,2*p],[0,0,1]]
    return d

F=[]
OP=[]
N=int(input())
for _ in range(N):
    X,Y=map(int,input().split())
    F.append([X,Y])
M=int(input())

for i in range(M):
    op=list(map(str, input().split()))
    if int(op[0])==1:
    
    elif int(op[0])==2:
    
    elif int(op[0])==3:
    
    else:
