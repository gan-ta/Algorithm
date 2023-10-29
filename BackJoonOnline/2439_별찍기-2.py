n = int(input())

for i in range(n):
    res = ""
    for j in range(n-(i+1)):
        res += " "
    for j in range(i+1):
        res += "*"
    print(res)