import sys
sys.stdin = open("input.txt", "r")

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    temp = list(map(int, input().split()))
    points_x = []
    points_m = []
    res = []

    for i in range(0, N):
        points_x.append(temp[i])

    for i in range(N, 2 * N):
        points_m.append(temp[i])

    for i in range(1, N):
        l = points_x[i-1]
        h = points_x[i]

        while h - l > 1 / (10**12):
            m = (h + l) / 2
            left = 0
            right = 0

            for j in range(N):
                force = points_m[j] / (m - points_x[j]) ** 2
                if points_x[j] < m:
                    left += force
                else:
                    right += force

            if left < right:
                h = m
            else:
                l = m

        res.append(m)
    print(f'#{test_case} {" ".join("%.10f" % f for f in res)}')




