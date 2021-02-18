n,k=map(int,input().split())
a=list(map(int,input().split()))

#約数列挙
def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    divisors.sort()
    return divisors

tmp=make_divisors(sum(a))[::-1]
for c in tmp:
    cnt=0
    for ca in a:
        if ca<c:
            cnt+=ca
        else:
            ca%=c
            if ca<c-ca:
                cnt+=ca
            else:
                cnt-=(c-ca)

    if cnt%c==0 and 0<=cnt<=2*k:
        print(c)
        exit()
