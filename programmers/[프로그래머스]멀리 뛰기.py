def solution(n):
    t1, t2 = 1, 1
    for i in range(2, n + 1):
        t2, t1 = t1 + t2, t2

    return t2 % 1234567