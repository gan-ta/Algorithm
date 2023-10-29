N = int(input())

res = 0
temp = input()

for i in range(len(temp)):
    res += int(temp[i])
    
print(res)