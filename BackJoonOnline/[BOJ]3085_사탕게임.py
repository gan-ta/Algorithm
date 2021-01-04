def calc_row_count(n):
    check_c = graph[n][0]
    check_num = 1
    ret = 0
    for i in range(1, N):
        if check_c == graph[n][i]:
            check_num += 1
        else:
            check_c = graph[n][i]
            ret = max(ret, check_num)
            check_num = 1
    return max(ret, check_num)


def calc_col_count(n):
    check_c = graph[0][n]
    check_num = 1
    ret = 0
    for i in range(1, N):
        if check_c == graph[i][n]:
            check_num += 1
        else:
            check_c = graph[i][n]
            ret = max(ret, check_num)
            check_num = 1
    return max(ret, check_num)


if __name__ == '__main__':
    N = int(input())
    graph = list()
    answer = 0

    for _ in range(N):
        graph.append(list(input()))

    # 행마다 판별
    for i in range(N):
        answer = max(answer,calc_row_count(i))

    # 열마다 판별
    for i in range(N):
        answer = max(answer,calc_col_count(i))

    for i in range(N):
        for j in range(N):
            # 밑 바꿈
            if i != N - 1:
                temp = graph[i][j]
                graph[i][j] = graph[i + 1][j]
                graph[i + 1][j] = temp
                # 조사 진행
                answer = max(answer, calc_row_count(i))
                answer = max(answer, calc_row_count(i + 1))
                answer = max(answer, calc_col_count(j))
                temp = graph[i][j]
                graph[i][j] = graph[i + 1][j]
                graph[i + 1][j] = temp
            # 우 바꿈
            if j != N - 1:
                temp = graph[i][j]
                graph[i][j] = graph[i][j + 1]
                graph[i][j + 1] = temp
                # 조사 진행
                answer = max(answer, calc_col_count(j))
                answer = max(answer, calc_col_count(j + 1))
                answer = max(answer, calc_row_count(i))
                temp = graph[i][j]
                graph[i][j] = graph[i][j + 1]
                graph[i][j + 1] = temp

    print(answer)
