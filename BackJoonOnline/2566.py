if __name__ == "__main__":
    matrix = []

    for _ in range(9):
        matrix.append(list(map(int, input().split())))

    a = -1
    b = -1
    max_value = -1

    for i in range(9):
        for j in range(9):
            if max_value < matrix[i][j]:
                max_value = matrix[i][j]
                a = i
                b = j

    print(max_value)
    print(f"{a + 1} {b + 1}")