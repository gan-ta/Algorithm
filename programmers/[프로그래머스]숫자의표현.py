from collections import deque


def solution(n):
    answer = 1

    q = deque()

    # 현재의 끝 값, 누적값
    for i in range(1, n + 1):
        q.appendleft([i, i])

    while len(q) != 0:
        search = q.pop()

        last_num = search[0]
        value = search[1]

        if value + last_num + 1 < n:
            q.appendleft([last_num + 1, value + last_num + 1])
        elif value + last_num + 1 == n:
            answer += 1
        else:
            pass

    return answer