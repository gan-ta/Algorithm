if __name__ == "__main__":
    matrix = []

    for i in range(5):
        temp = input()
        matrix.append([])
        for c in temp:
            matrix[i].append(c)
        temp_len = len(matrix[i])
        for _ in range(15 - temp_len):
            matrix[i].append("")

    res = ""
    for j in range(15):
        for i in range(5):
            res += matrix[i][j]

    print(res)