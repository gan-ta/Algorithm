import sys

input = sys.stdin.readline


def solve(idx):
    # 정답의 도출
    if idx == len(zero):
        for b in board:
            b = list(map(str, b))
            print(" ".join(b))
        sys.exit(0)

    # 조사 점을 가져옴
    r, c = zero[idx]

    # 값이 채워져 있지 않은 경우
    for n in range(1, 10):

        is_valid = True

        # 유효 수 조사
        for i in range(9):
            if board[r][i] == n:
                is_valid = False
                break
            if board[i][c] == n:
                is_valid = False
                break

        for i in range(3):
            for j in range(3):
                if board[r // 3 * 3 + i][c // 3 * 3 + j] == n:
                    is_valid = False
                    break
            if not is_valid:
                break

        if not is_valid:
            continue

        board[r][c] = n
        solve(idx + 1)
        board[r][c] = 0


global zero
global board

if __name__ == '__main__':
    zero = []
    board = [list(map(int, input().split())) for _ in range(9)]

    for r in range(9):
        for c in range(9):
            if board[r][c] == 0:
                zero.append((r, c))

    solve(0)
