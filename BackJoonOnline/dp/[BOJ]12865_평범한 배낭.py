if __name__ == '__main__':
    N, K = list(map(int, input().split()))

    bag_list = []

    dp = [[0] * (K + 1) for _ in range(N + 1)]  # 맨 끝 마진

    for _ in range(N):
        bag_list.append(list(map(int, input().split())))

    for i in range(1, N + 1):
        w = bag_list[i - 1][0]
        v = bag_list[i - 1][1]
        for j in range(1, K + 1):
            if j < w: # 이러면 넣지 못함
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w] + v)
    print(dp[-1][-1])


