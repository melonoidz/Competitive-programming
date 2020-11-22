sx, sy, gx, gy = map(int, input().split())
if sx <= gx:
    ans = sx+(abs(gx-sx)*sy/(sy+gy))
else:
    ans = sx-(abs(gx-sx)*sy/(sy+gy))
print(ans)
