a, b, n = map(int, input().split())
p = []
T = list(map(str, input().split()))
for t in T:
    if t == "G":
        p.append(0)
    else:
        p.append(int(t))
ans = 0
point = [0]*(a+1)
frame = 1
cnt = 0
spare = 0
strike = 0
while frame < a:  # 　最終フレームだけ別処理,strikeその場で探索
    x = p[cnt]
    if spare == 1:
        point[frame-1] += x
        spare -= 1

    if x == b:
        point[frame] += b
        frame += 1
        cnt += 1
        strike = 2
        while strike > 0 and cnt+strike <= n:
            point[frame-1] += p[cnt+strike-1]
            strike -= 1

    elif x != b:
        cnt += 1
        y = p[cnt]
        if x+y != b:
            point[frame] += x+y
        else:
            point[frame] += x+y
            spare = 1
        frame += 1
        cnt += 1

v = p[cnt]
w = p[cnt+1]
if v == b or w == b or v+w == b:
    z = p[-1]
    if v == b and w != b:  # st and not st
        point[frame] += v+2*w+2*z
    elif v == b and w == b:  # st and st
        point[frame] += (v+2*w+3*z)
    elif v != b and v+w == b:  # spa
        point[frame] += v+w+2*z
else:
    point[frame] = v+w
print(sum(point))
