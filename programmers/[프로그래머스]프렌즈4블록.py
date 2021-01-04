def delete_unit(r, c, n, m, board, visited):
    if c == n - 1 or r == m - 1 or visited[r][c] == 1 or board[r][c] == '#':
        return False

    # 2x2검사
    if board[r][c] == board[r + 1][c] and board[r][c] == board[r][c + 1] and board[r][c] == board[r + 1][c + 1]:
        delete_unit(r + 1, c, n, m, board, visited)
        delete_unit(r, c + 1, n, m, board, visited)
        delete_unit(r + 1, c + 1, n, m, board, visited)
        visited[r][c] = 1
        visited[r + 1][c] = 1
        visited[r][c + 1] = 1
        visited[r + 1][c + 1] = 1
        return True

    return False


def solution(m, n, board):
    answer = 0

    for i, arr in enumerate(board):
        board[i] = list(arr)

    while True:
        check = False

        visited = []
        for _ in range(m):
            visited.append([0] * n)

        for r in range(m):
            for c in range(n):
                if delete_unit(r, c, n, m, board, visited):
                    check = True

        if check:
            for c in range(n):
                stack = []
                for r in range(m):
                    if board[r][c] != '#' and visited[r][c] != 1:
                        stack.append(board[r][c])

                for r in range(m - 1, -1, -1):
                    if len(stack) != 0:
                        board[r][c] = stack.pop()
                    else:
                        board[r][c] = '#'
        else:
            break

    for row in board:
        answer += row.count('#')

    return answer