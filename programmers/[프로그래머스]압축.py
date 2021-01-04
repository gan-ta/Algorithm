def solution(msg):
    answer = []
    index_dict = dict()

    for i in range(ord('A'), ord('Z') + 1):
        c = chr(i)
        index_dict[c] = i - (ord('A') - 1)

    point_idx = 0
    while point_idx < len(msg):
        next_idx = -1
        for i in range(point_idx + 1, len(msg) + 1):
            if msg[point_idx:i] not in index_dict.keys():
                next_idx = i - 1
                break
        check = 0
        if next_idx == -1:
            next_idx = len(msg)
            check = 1

        answer.append(index_dict[msg[point_idx:next_idx]])
        if check == 0:
            index_dict[msg[point_idx: next_idx + 1]] = len(index_dict) + 1
        point_idx = next_idx

    return answer
