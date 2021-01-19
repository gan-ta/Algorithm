def get_parent(node, parent_list):
    if parent_list[node] == node:
        return node

    return get_parent(parent_list[node], parent_list)


def check_parent(node1, node2, parent_list):
    if get_parent(node1, parent_list) == get_parent(node2, parent_list):
        return True

    return False


def union_parent(node1, node2, parent_list):
    parent1 = get_parent(node1, parent_list)
    parent2 = get_parent(node2, parent_list)

    parent_list[parent1] = parent2


def solution(n, costs):
    answer = 0

    graph = [[0] * n for _ in range(n)]

    parent_list = [num for num in range(0, n)]

    costs.sort(key=lambda x: x[2])

    count = 0

    for cost in costs:
        if count == n - 1:
            break

        if check_parent(cost[0], cost[1], parent_list):
            pass
        else:
            count += 1
            union_parent(cost[0], cost[1], parent_list)
            answer += cost[2]

    return answer