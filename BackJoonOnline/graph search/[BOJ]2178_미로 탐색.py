from collections import deque

if __name__ == '__main__':
    N, M = list(map(int, input().split()))

    board = [list(map(int, input())) for _ in range(N)]

    dr = [1,0,-1,0]
    dc = [0,1,0,-1]

    dq = deque()

    dq.append([0,0,1])
    board[0][0] = -1
    ans_list = []

    while len(dq) != 0:

        search = dq.pop()

        if search[0] == N-1 and search[1] == M-1:
            ans_list.append(search)

        for i in range(4):
            nr = search[0] + dr[i]
            nc = search[1] + dc[i]

            if 0<= nr < N and 0<= nc < M:
                if board[nr][nc] == 1:
                    board[nr][nc] = 0
                    dq.appendleft([nr,nc, search[2] + 1])

    ans_list.sort(key = lambda x : x[2])
    print(ans_list[-1][2])
