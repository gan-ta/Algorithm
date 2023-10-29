N, M = list(map(int, input().split()))
bucket = [i + 1 for i in range(N)]


for _ in range(M):
    i, j = list(map(int, input().split()))
    temp = bucket[i - 1]
    bucket[i - 1] = bucket[j - 1]
    bucket[j - 1] = temp

res = ""
for ball in bucket:
    res += str(ball) + " "

print(res.strip())
