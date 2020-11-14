s = input()
cnt = [0]*10

if len(s) <= 2:
    if int(s) % 8 == 0 or int(s[::-1]) % 8 == 0:
        print("Yes")
    else:
        print("No")
    exit()

for a in s:
    cnt[int(a)] += 1
for i in range(1, 10):
    for j in range(1, 10):
        for k in range(1, 10):
            tmp = i*100+j*10+k
            if tmp % 8 == 0:
                ry = [0]*10
                ry[i] += 1
                ry[j] += 1
                ry[k] += 1
                ok = True
                for y in range(1, 10):
                    if cnt[y] < ry[y]:
                        ok = False
                if ok:
                    print("Yes")
                    exit()
print("No")
