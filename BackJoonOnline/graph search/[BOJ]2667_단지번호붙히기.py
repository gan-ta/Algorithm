from collections import deque


if __name__ == '__main__':
    N = int(input())
    board = []

    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]

    for _ in range(N):
        insert = list(map(int, list(input())))
        board.append(insert)

    dq = deque()
    ans = []

    for r in range(N):
        for c in range(N):
            if board[r][c] != 1:
                continue

            board[r][c] = -1
            dq.appendleft([r, c])
            count = 1

            while len(dq) != 0:
                search = dq.pop()

                for k in range(4):
                    nr = search[0] + dr[k]
                    nc = search[1] + dc[k]

                    if 0 <= nr < N and 0 <= nc < N:
                        if board[nr][nc] == 1:
                            count += 1
                            board[nr][nc] = -1
                            dq.appendleft([nr, nc])

            ans.append(count)

    ans.sort()
    print(len(ans))
    for a in ans:
        print(a)