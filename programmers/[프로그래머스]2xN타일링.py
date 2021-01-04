def solution(n):
    dp = list()
    dp.append(1)
    dp.append(2)

    for i in range(2, n):
        dp.append((dp[-1] + dp[-2]) % 1000000007)

    return dp[n - 1]