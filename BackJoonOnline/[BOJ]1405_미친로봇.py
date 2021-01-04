global answer


def dfs(sr, sc, depth, directionList):
    global answer
    if depth == N:
        temp = 1
        for num in directionList:
            temp *= percent_list[num]
        answer += temp
        return

    for i in range(0, 4):
        nr = sr + dr[i]
        nc = sc + dc[i]

        if visited[nr][nc] == 0:
            visited[nr][nc] = 1
            dfs(nr, nc, depth + 1, directionList + [i])
            visited[nr][nc] = 0


if __name__ == '__main__':
    N, percentE, percentW, percentS, percentN = list(map(int,input().split()))
    global answer
    answer = 0

    # 동,서, 남, 북
    percent_list = [int(percentE) * 1 / 100, int(percentW) * 1 / 100, int(percentS) * 1 / 100, int(percentN) * 1 / 100]
    dr = [0, 0, 1, -1]
    dc = [1, -1, 0, 0]

    visited = list()
    for _ in range(30):
        visited.append([0 for n in range(30)])

    visited[15][15] = 1

    dfs(15, 15, 0, [])

    print('%.9f' % answer)
