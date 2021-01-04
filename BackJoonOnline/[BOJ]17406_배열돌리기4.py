from itertools import permutations


def calc_graph(action_graph):
    ret = 1000000

    for row in action_graph:
        temp_ret = sum(row)
        ret = min(ret, temp_ret)

    return ret


# 회전 돌린거를 다른 객체 그래프로써 반환
def simulation(start_list, end_list, action_graph):
    start_r = start_list[0]
    start_c = start_list[1]
    end_r = end_list[0]
    end_c = end_list[1]
    len_r = end_r - start_r
    len_c = end_c - start_c

    # 기존의 그래프를 복사
    simulation_graph = list()
    for arr in action_graph:
        simulation_graph.append(arr[:])

    # 종료조건
    if len_r <= 0 or len_c <= 0:
        return simulation_graph

    # 엑션을 취함
    # 상 row 회전
    temp_point = simulation_graph[start_r][start_c]
    for tc in range(start_c, end_c):
        temp_point2 = simulation_graph[start_r][tc+1]
        simulation_graph[start_r][tc+1] = temp_point
        temp_point = temp_point2

    # 우 col 회전
    for tr in range(start_r, end_r):
        temp_point2 = simulation_graph[tr+1][end_c]
        simulation_graph[tr+1][end_c] = temp_point
        temp_point = temp_point2

    # 하 row 회전
    for tc in range(end_c, start_c, -1):
        temp_point2 = simulation_graph[end_r][tc-1]
        simulation_graph[end_r][tc-1] = temp_point
        temp_point = temp_point2

    # 좌 col 회전
    for tr in range(end_r, start_r, -1):
        temp_point2 = simulation_graph[tr-1][start_c]
        simulation_graph[tr-1][start_c] = temp_point
        temp_point = temp_point2

    return simulation([start_r + 1, start_c + 1], [end_r - 1, end_c - 1], simulation_graph)


if __name__ == '__main__':
    n, m, k = map(int, input().split())
    graph = list()
    action_list = list()
    pick_list = [num for num in range(0, k)]
    answer = 1000000

    for _ in range(n):
        graph.append(list(map(int, input().split())))

    for _ in range(k):
        action_list.append(list(map(int, input().split())))

    # s와 c를 1씩 빼주고 고려
    for pick_situation in permutations(pick_list, k):
        insert_graph = list()
        for arr in graph:
            insert_graph.append(arr[:])

        for pick_num in pick_situation:
            pick = action_list[pick_num]
            insert_start_list = [pick[0] - pick[2] - 1, pick[1] - pick[2] - 1]
            insert_end_list = [pick[0] + pick[2] - 1, pick[1] + pick[2] - 1]
            insert_graph = simulation(insert_start_list, insert_end_list, insert_graph)

        temp_answer = calc_graph(insert_graph)

        answer = min(answer, temp_answer)

    print(answer)
