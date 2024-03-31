N, M = list(map(int, str(input()).split(" ")))
tree_list = list(map(int, str(input()).split(" ")))

low = 0
hight = max(tree_list)

answer = 0


def get_remain_tree(tree_list, limit):
    res = 0

    for tree in tree_list:
        temp_tree = tree - limit
        if temp_tree > 0:
            res += (tree - limit)

    return res


while True:
    if low > hight:
        break

    mid = (low + hight) // 2
    temp = get_remain_tree(tree_list, mid)

    if temp >= M:
        answer = max(answer, mid)
        low = mid + 1
    else:
        hight = mid - 1

print(answer)
