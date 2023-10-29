import sys
sys.setrecursionlimit(10**5)

direction = [[0, 1], [1, 0], [-1, 0], [0, -1]]


def dfs(r, c, maps):
    if r >= len(maps) or r < 0:
        return 0
    if c >= len(maps[r]) or c < 0:
        return 0

    if maps[r][c] == 'X':
        return 0

    res = int(maps[r][c])
    maps[r][c] = 'X'
    for d in direction:
        res += dfs(r + d[0], c + d[1], maps)

    return res


def solution(maps):
    answer = []
    maps = [[v for v in r] for r in maps]

    for i in range(0, len(maps)):
        for j in range(0, len(maps[i])):
            out = dfs(i, j, maps)
            if out != 0:
                answer.append(out)

    if len(answer) == 0:
        return [-1]

    return sorted(answer)


if __name__ == '__main__':
    print(solution(["XXX","XXX","XXX"]))
