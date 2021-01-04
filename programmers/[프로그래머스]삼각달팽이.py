from itertools import chain


def solution(n):
    answer = [[0 for _ in range(n)] for _ in range(n)]

    insert = 1
    y = -1
    x = 0
    for i in range(n):
        for j in range(i, n):
            if i % 3 == 0:
                y += 1
            elif i % 3 == 1:
                x += 1
            elif i % 3 == 2:
                y -= 1
                x -= 1
            answer[y][x] = insert
            insert += 1

    return [i for i in chain(*answer) if i != 0]