import numpy as np

N = int(input())

t_arr = np.zeros(N)
l_arr = np.zeros(N)
r_arr = np.zeros(N)

tmp_arr = []

for i in range(N):
    t, l, r = map(int, input().split())

    t_arr[i] = t
    l_arr[i] = l
    r_arr[i] = r
    tmp = [l, r, t]
    # if t == 1:
    #     tmp = [l-1, r+1]
    # elif t == 2:
    #     tmp = [l-1, r]
    # elif t == 3:
    #     tmp = [l, r+1]
    # elif t == 4:
    #     tmp = [l, r]
    tmp_arr.append(tmp)

ans = 0
for i in range(N):
            
    for j in range(1, N-i):
        # print(tmp_arr[i])
        # print(tmp_arr[i+j])
    
        if ((tmp_arr[i][0] <= tmp_arr[i+j][0]) and (tmp_arr[i+j][0] <= tmp_arr[i][1])) or ((tmp_arr[i][0] <= tmp_arr[i+j][1]) and (tmp_arr[i+j][1] <= tmp_arr[i][1])):
            

            if (tmp_arr[i][1] == tmp_arr[i+j][0]):
                if (tmp_arr[i][2] in [1, 3]) and (tmp_arr[i+j][2] in [3, 4]):
                    ans -= 1
                    # print('] and (')
                elif (tmp_arr[i][2] in [2, 4]) and (tmp_arr[i+j][2] in [1, 2]):
                    ans -= 1
                    # print(') and [')
            elif (tmp_arr[i][0] == tmp_arr[i+j][1]):
                if (tmp_arr[i][2] in [1, 2]) and (tmp_arr[i+j][2] in [2, 4]):
                    ans -= 1
                    # print('[ and )')
 
                elif (tmp_arr[i][2] in [3, 4]) and (tmp_arr[i+j][2] in [1, 3]):
                    ans -= 1
                    # print('( and ]')
            ans += 1
 
        elif ((tmp_arr[i+j][0] <= tmp_arr[i][0]) and (tmp_arr[i][0] <= tmp_arr[i+j][1])) or ((tmp_arr[i+j][0] <= tmp_arr[i][1]) and (tmp_arr[i][1] <= tmp_arr[i+j][1])):
            if (tmp_arr[i][1] == tmp_arr[i+j][0]):
                if (tmp_arr[i][2] in [1, 3]) and (tmp_arr[i+j][2] in [3, 4]):
                    ans -= 1
                    # print('] and (')
                elif (tmp_arr[i][2] in [2, 4]) and (tmp_arr[i+j][2] in [1, 2]):
                    ans -= 1
                    # print(') and [')
            elif (tmp_arr[i][0] == tmp_arr[i+j][1]):
                if (tmp_arr[i][2] in [1, 2]) and (tmp_arr[i+j][2] in [2, 4]):
                    ans -= 1
                    # print('[ and )')
 
                elif (tmp_arr[i][2] in [3, 4]) and (tmp_arr[i+j][2] in [1, 3]):
                    ans -= 1
                    # print('( and ]')
 
            ans += 1
 

print(ans)

#     tmp_arr[i] = []
# t, l, r = map(int, input())
# a = list(map(int, input()))

# print(a)