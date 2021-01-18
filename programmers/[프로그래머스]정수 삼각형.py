def solution(triangle):
    dp = []
    dp.append(triangle[0])

    for i in range(1, len(triangle)):
        temp = []
        for j in range(len(triangle[i])):
            insert_num = -1
            if j - 1 >= 0:
                insert_num = max(insert_num, dp[i - 1][j - 1] + triangle[i][j])

            if j < len(triangle[i]) - 1:
                insert_num = max(insert_num, dp[i - 1][j] + triangle[i][j])
            temp.append(insert_num)
        dp.append(temp)

    return max(dp[-1])