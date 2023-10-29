from collections import deque


def solution(x, y, n):
    answer = -1
    dq = deque()
    visited = [0 for i in range(1000001)]
    dq.append([x, 0])
    visited[x] = 1

    while dq:
        item = dq.popleft()
        if item[0] == y:
            answer = item[1]
            break
        if item[0] + n <= y and visited[item[0] + n] == 0:
            visited[item[0] + n] = 1
            dq.append([item[0] + n, item[1] + 1])
        if item[0] * 2 <= y and visited[item[0] * 2] == 0:
            visited[item[0] * 2] = 1
            dq.append([item[0] * 2, item[1] + 1])
        if item[0] * 3 <= y and visited[item[0] * 3] == 0:
            visited[item[0] * 3] = 1
            dq.append([item[0] * 3, item[1] + 1])

    return answer


if __name__ == '__main__':
    print(solution(10, 40, 30))
