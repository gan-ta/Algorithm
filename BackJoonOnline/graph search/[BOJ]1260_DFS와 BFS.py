from collections import deque

global board
global visited
global N, M, V
res1 = []
res2 = []


def dfs(s):
    res1.append(s + 1)
    if visited.count(0) == 0:  # 다 방문 하였으면
        return

    visited[s] = 1

    for i in range(N):
        if board[s][i] != 0 and visited[i] == 0:
            visited[i] = 1
            dfs(i)
    return


if __name__ == '__main__':
    N, M, V = list(map(int, input().split()))

    edge_info = []

    for _ in range(M):
        insert = list(map(int, input().split()))
        edge_info.append(insert)

    board = [[0] * N for _ in range(N)]
    visited = [0] * N

    for e in edge_info:
        board[e[0] - 1][e[1] - 1] = 1
        board[e[1] - 1][e[0] - 1] = 1

    dfs(V - 1)

    dq = deque()
    dq.appendleft(V - 1)
    visited = [0] * N

    while len(dq) != 0:
        search = dq.pop()

        res2.append(search + 1)
        visited[search] = 1
        for i in range(N):
            if board[search][i] != 0 and visited[i] == 0:
                visited[i] = 1
                dq.appendleft(i)

    res1 = list(map(str, res1))
    res2 = list(map(str, res2))
    print(' '.join(res1))
    print(' '.join(res2))
