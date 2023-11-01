if __name__ == "__main__":
    T = int(input())

    matrix = []

    for _ in range(100):
        matrix.append([0 for i in range(100)])

    for _ in range(T):
        x, y = list(map(int, input().split()))
        for i in range(x, x + 10):
            for j in range(y, y + 10):
                matrix[i][j] = 1

    res = 0

    for i in range(100):
        for j in range(100):
            res += matrix[i][j]
    print(res)