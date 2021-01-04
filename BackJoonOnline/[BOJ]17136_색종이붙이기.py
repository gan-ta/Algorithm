def check_attach(check_r, check_c, distance):
    for nr in range(distance):
        for nc in range(distance):
            if graph[check_r + nr][check_c + nc] == 0:
                return False
    return True


def attach(check_r, check_c, distance):
    for nr in range(distance):
        for nc in range(distance):
            graph[check_r + nr][check_c + nc] = 0


def detach(check_r, check_c, distance):
    for nr in range(distance):
        for nc in range(distance):
            graph[check_r + nr][check_c + nc] = 1


def dfs(remain_one):
    global answer
    use_paper = sum([5 - n for n in paper[1:]])

    if use_paper >= answer:
        return

    if remain_one == 0:
        answer = min(answer, use_paper)
        return

    if sum(paper) == 0:
        return

    for i in range(10):
        for j in range(10):
            if graph[i][j] == 0:  # 1일때만 조사
                continue

            for distance in range(5, 0, -1):
                if paper[distance] > 0 and i + distance <= 10 and j + distance <= 10:
                    if check_attach(i, j, distance):
                        attach(i, j, distance)
                        paper[distance] -= 1
                        dfs(remain_one - pow(distance, 2))
                        paper[distance] += 1
                        detach(i, j, distance)

            return  # 이 조건이 결정타였음, 여기에서 안끝나면 너무 많이 돌음


if __name__ == '__main__':
    graph = list()
    one_count = 0
    answer = 100
    paper = [0, 5, 5, 5, 5, 5]

    for _ in range(10):
        temp = list(map(int, input().split()))
        one_count += temp.count(1)
        graph.append(temp)

    dfs(one_count)
    if answer == 100:
        answer = -1
    print(answer)
