import math


def solution(a):
    answer = 2
    left_min = [0] * len(a)
    right_min = [0] * len(a)

    left, right = math.inf, math.inf

    # 왼쪽 최소값 저장
    for i in range(len(a)):
        if left > a[i]:
            left = a[i]
        left_min[i] = left

    # 오른쪽 최소값 저장
    for i in range(len(a) - 1, -1, -1):
        if right > a[i]:
            right = a[i]
        right_min[i] = right

    # 수마다 확인
    for i in range(1, len(a) - 1):
        if a[i] > left_min[i - 1] and a[i] > right_min[i + 1]:
            continue
        answer += 1

    return answer