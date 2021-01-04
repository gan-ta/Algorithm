from collections import deque


def solution(priorities, location):
    answer = 0

    q = deque()
    weight_list = []

    for i, v in enumerate(priorities):
        q.appendleft((i, v))
        weight_list.append(v)

    temp_location = 1

    while len(q) != 0:
        search = q.pop()
        check = 0
        if any(weight > search[1] for weight in weight_list):
            check = 1

        if check == 1:
            q.appendleft(search)
        else:
            if search[0] == location:
                answer = temp_location
            weight_list.remove(search[1])
            temp_location += 1

    return answer
