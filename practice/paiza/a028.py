S, P = map(int, input().split())
while P >= 0:
    if S*P <= 100:
        S += (S*P)//100
        print(S)
        exit()
    else:
        for q in range(1, P+1):
            if S*q > 100:
                S += (q*S)//100
                P -= q
                break
