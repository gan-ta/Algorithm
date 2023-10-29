N, M = list(map(int, input().split()))
bucket = [0 for _ in range(N)]

for a in range(M):
    i, j, k = list(map(int, input().split()))

    for b in range(i-1, j):
        bucket[b] = k

res = ""
for ball in bucket:
    res += str(ball) + " "

print(res.strip())