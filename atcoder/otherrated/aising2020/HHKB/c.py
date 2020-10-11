n = int(input())
p = list(map(int, input().split()))
num = 0
tmp = [0]*210000
for a in p:
    tmp[a] += 1
    if a == num:
        while tmp[num] != 0:
            num += 1
    print(num)
