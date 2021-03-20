import math
P=float(input())
 
if P < (1.5 / math.log(2)):
    t = P
else:
    t = 1.5 / math.log(2) - 1.5 * math.log2(1.5 / P / math.log(2))
print(t)