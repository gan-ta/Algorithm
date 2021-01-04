from collections import deque


def solution(progresses, speeds):
    answer = []

    q = deque()

    for a, b in zip(speeds, progresses):
        q.appendleft([a, b])

    while len(q) != 0:
        # 진도 값 갱신
        idx = 0
        aim = len(q)
        while idx != aim:
            search = q.pop()
            idx += 1
            q.appendleft([search[0], search[0] + search[1]])

        # 완료 작업물 꺼냄
        check = 0
        while len(q) != 0:
            search = q.pop()
            check += 1
            if search[1] < 100:
                q.append(search)
                check -= 1
                break

        if check != 0:
            answer.append(check)

    return answer
