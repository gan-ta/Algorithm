global graph

global zero_count
global one_count


def check_square(r, c, l):
    global zero_count
    global one_count
    global graph

    zero_flag = True
    one_flag = True

    for i in range(l):
        for j in range(l):
            if graph[r + i][c + j] == 1:
                zero_flag = False
                break
        if not zero_flag:
            break

    if zero_flag:
        return 0

    for i in range(l):
        for j in range(l):
            if graph[r + i][c + j] == 0:
                one_flag = False
                break
        if not one_flag:
            break

    if one_flag:
        return 1

    return 2


def dfs(r, c, l):
    global zero_count
    global one_count
    global graph

    if l == 1:
        if graph[r][c] == 0:
            zero_count += 1
        elif graph[r][c] == 1:
            one_count += 1
        return

    check_num = check_square(r, c, l)

    if check_num == 0:
        zero_count += 1
        return
    elif check_num == 1:
        one_count += 1
        return
    else:
        # 이분 탐색 시작
        nr = r + (l // 2)
        nc = c + (l // 2)
        nl = l // 2
        dfs(r, c, nl)
        dfs(nr, c, nl)
        dfs(r, nc, nl)
        dfs(nr, nc, nl)


if __name__ == '__main__':
    N = int(input())
    graph = []

    for _ in range(N):
        graph.append(list(map(int, input().split())))

    zero_count = 0
    one_count = 0

    dfs(0, 0, N)

    print(zero_count)
    print(one_count)
