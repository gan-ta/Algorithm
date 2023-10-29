if __name__ == '__main__':
    x = int(input())
    n = int(input())

    res = 0

    for i in range(0, n):
        a, b = list(map(int, input().split()))
        res += a * b

    if res == x:
        print("Yes")
    else:
        print("No")
