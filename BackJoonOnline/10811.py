N, M = list(map(int, input().split()))
bucket = [i + 1 for i in range(N)]

for _ in range(M):
    i, j = list(map(int, input().split()))
    i -= 1
    j -= 1

    for k in range(int((j - i + 1) / 2)):
        temp = bucket[i + k]
        bucket[i + k] = bucket[j - k]
        bucket[j - k] = temp

res = ""

for num in bucket:
    res += str(num) + " "

print(res.strip())
