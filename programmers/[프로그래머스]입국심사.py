from functools import reduce


def check(mid, times, n):
    if n <= reduce(lambda acc, cur: acc + int(mid / cur), times, 0):
        return True
    return False


def solution(n, times):
    answer = 0
    max_num = max(times)

    left = 0
    right = max_num * n

    while left < right:
        mid = int((left + right) / 2)
        if check(mid, times, n):
            answer = mid
            right = mid
        else:
            left = mid + 1

    return answer

print(solution(6,[7,10]))