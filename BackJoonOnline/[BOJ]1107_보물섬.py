from collections import deque


dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]


def bfs(sr, sc):
    ret = 0

    q = deque()
    q.appendleft([sr, sc, 0])
    visited[sr][sc] = True

    while len(q) != 0:
        search = q.pop()
        ret = search[2]
        for d in range(4):
            nr = search[0] + dr[d]
            nc = search[1] + dc[d]
            if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc]:
                visited[nr][nc] = True
                q.appendleft([nr, nc, search[2] + 1])

    return ret


if __name__ == "__main__":
    answer = 0
    R, C = map(int, input().split())
    graph = [input() for _ in range(R)]

    for i in range(R):
        for j in range(C):
            if graph[i][j] == 'L':
                visited = list()
                for r in graph:
                    visited.append([c == 'W' for c in r])
                answer = max(answer, bfs(i, j))

    print(answer)
