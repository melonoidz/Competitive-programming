n = int(input())
p = list(map(int, input().split()))
num = 0
tmp = []
for a in p:
    tmp.append(a)
    if a == num:
        while num in tmp:
            num += 1
    print(num)
