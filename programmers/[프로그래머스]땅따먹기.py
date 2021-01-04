def solution(land):
    answer = 0
    row_len = len(land)
    col_len = len(land[0])

    dp = [[0] * col_len for _ in range(row_len)]

    for i in range(0, col_len):
        dp[0][i] = land[0][i]

    for i in range(1, row_len):
        for j in range(0, col_len):
            insert_max = max(dp[i - 1][:j] + dp[i - 1][j + 1:])
            dp[i][j] = insert_max + land[i][j]

    answer = max(dp[row_len - 1])

    return answer
