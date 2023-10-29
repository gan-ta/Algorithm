n = int(input())
num_list = list(map(int, input().split()))
v = int(input())

res = 0

for num in num_list:
    if num == v:
        res += 1

print(res)