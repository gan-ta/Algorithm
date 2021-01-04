def solution(board):
    answer = 0

    row_len = len(board)
    col_len = len(board[0])

    check = []
    for _ in range(row_len):
        check.append([0] * col_len)

    for r in range(row_len):
        if board[r][0] == 1:
            check[r][0] = 1
            answer = 1
    for c in range(col_len):
        if board[0][c] == 1:
            check[0][c] = 1
            answer = 1

    for r in range(1, row_len):
        for c in range(1, col_len):
            if board[r][c] == 1:
                insert = min(check[r - 1][c], check[r][c - 1], check[r - 1][c - 1])
                check[r][c] = insert + 1
                answer = max(answer, insert + 1)

    return pow(answer, 2)