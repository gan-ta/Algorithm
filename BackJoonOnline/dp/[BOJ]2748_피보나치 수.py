
if __name__ == '__main__':
    N = int(input())

    dp = []

    dp = [0] * 100

    dp[1] = 1

    for i in range(2, N+1):
        dp[i] = dp[i-1] + dp[i-2]

    print(dp[N])


