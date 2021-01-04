import sys
sys.setrecursionlimit(100000)

map_list = list()
check_list = list()

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

N = 0


def search_secure(tr, tc):
    check_list[tr][tc] = False

    for d in range(0, 4):
        nr = tr + dr[d]
        nc = tc + dc[d]
        if 0 <= nr < N and 0 <= nc < N and check_list[nr][nc]:
            search_secure(nr, nc)


if __name__ == '__main__':
    answer = 1
    N = int(input())
    max_depth = -1

    for i in range(0, N):
        map_list.append([int(c) for c in input().split()])

    max_depth = max([n for row in map_list for n in row])

    for i in range(1, max_depth):
        # 잠긴 부분 체크
        temp_answer = 0
        check_list = [list(map(lambda x: x > i, map_l)) for map_l in map_list]

        for r in range(0, len(check_list)):
            for c in range(0, len(check_list[r])):
                if check_list[r][c]:
                    search_secure(r, c)
                    temp_answer += 1

        if answer < temp_answer:
            answer = temp_answer

    print(answer)
