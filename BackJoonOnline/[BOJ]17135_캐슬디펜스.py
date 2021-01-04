from itertools import combinations


def search(location):
    catch_set = set()
    copy_graph = [['0'] * M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            copy_graph[i][j] = graph[i][j]

    for i in range(N, 0, -1):
        catch_set_list = [[], [], []]

        for j in range(0, i):
            for k in range(0, M):
                for l, num in enumerate(location):
                    diff = abs(i - j) + abs(num - k)
                    if diff <= D and copy_graph[j][k] == '1':
                        catch_set_list[l].append([j, k, diff])

        # set에다가 저장
        for catch_set_list_row in catch_set_list:
            if len(catch_set_list_row) != 0:
                insert = sorted(catch_set_list_row, key=lambda x: (x[2], x[1]))[0]
                catch_set.add((insert[0], insert[1]))
                copy_graph[insert[0]][insert[1]] = '0'

    return len(catch_set)


if __name__ == '__main__':
    N, M, D = map(int, input().split())
    graph = list()
    answer = -1

    location_combination = combinations([i for i in range(M)], 3)

    for _ in range(N):
        graph.append(input().split())

    # 궁수의 모든 위치 조합 확인
    for location_list in location_combination:
        answer = max(answer, search(location_list))

    print(answer)
