res = -1
res_idx = -1

for i in range(9):
    temp = int(input())
    if res < temp:
        res_idx = i + 1
        res = temp


print(res)
print(res_idx)