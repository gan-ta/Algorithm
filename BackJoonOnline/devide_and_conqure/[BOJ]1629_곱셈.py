def mpow(a, b, c):
    if b == 0:
        return 1

    res = mpow(a, b // 2, c)
    res = (res * res) % c
    if b % 2 == 1:
        res = (res * a) % c
    return res


if __name__ == '__main__':
    A, B, C = list(map(int, input().split()))

    print(mpow(A, B, C))
