import itertools
c = list(map(int, input().split()))
s = sum(c)
for g in itertools.product([0, 1], repeat=4):
    y = list(g)
    if y.count(1) > 0:
        to = 0
        for i in range(4):
            if y[i] == 1:
                to += c[i]
        if to == s-to:
            print("Yes")
            exit()
print("No")
