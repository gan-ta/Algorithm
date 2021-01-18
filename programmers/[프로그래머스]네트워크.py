from collections import deque


def solution(n, computers):
    answer = 0
    q = deque()
    visited = [0] * n

    for i in range(n):
        if visited[i] == 0:
            answer += 1
            visited[i] = 1
            q.appendleft(i)
            while len(q) != 0:
                search = q.pop()
                for j in range(n):
                    if j != n and visited[j] == 0 and computers[search][j] == 1:
                        visited[j] = 1
                        q.appendleft(j)

    return answer