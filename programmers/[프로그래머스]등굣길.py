def solution(m, n, puddles):
    answer = 0
    new_puddle = []

    dp = [[0] * m for _ in range(n)]

    dp[0][0] = 1

    for puddle in puddles:
        new_puddle.append([puddle[1] - 1, puddle[0] - 1])

    for i in range(n):
        for j in range(m):

            if [i, j] in new_puddle:
                continue

            if i != 0:
                dp[i][j] += (dp[i - 1][j] % 1000000007)
            if j != 0:
                dp[i][j] += (dp[i][j - 1] % 1000000007)

    return dp[n - 1][m - 1] % 1000000007