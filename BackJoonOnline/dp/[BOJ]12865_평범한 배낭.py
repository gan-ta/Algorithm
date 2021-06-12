if __name__ == '__main__':
    N, K = list(map(int, input().split()))

    bag_list = []

    dp = [[0] * (K + 1) for _ in range(N + 1)]  # 맨 끝 마진

    for _ in range(N):
        bag_list.append(list(map(int, input().split())))

    for i in range(1, N + 1):
        # 현재 조사
        w = bag_list[i - 1][0]
        v = bag_list[i - 1][1]
        for j in range(1, K + 1):
            if j < w:  # 이러면 못넣음
                dp[i][j] = dp[i - 1][j]
            else:  # 이러면 넣어주는데 가장 유망한 것을 넣어줌(안넣어 준 것이랑 넣어준 것)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v)

    res = 0
    for l in dp:
        res = max(res, max(l))
    print(res)

