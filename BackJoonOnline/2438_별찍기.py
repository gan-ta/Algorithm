a = int(input())

for i in range(a):
    res = ""
    for j in range(i + 1):
        res += "*"
    print(res)