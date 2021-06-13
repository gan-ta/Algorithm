if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    coins = []
    dp = [0 for i in range(k + 1)]

    for i in range(n):
        coins.append(int(input()))

    coins.sort()

    dp = [10001] * (k + 1)
    dp[0] = 0

    for i in range(n):
        for j in range(coins[i], k + 1):
            dp[j] = min(dp[j], dp[j - coins[i]] + 1)

    if dp[-1] == 10001:
        print(-1)
    else:
        print(dp[-1])

