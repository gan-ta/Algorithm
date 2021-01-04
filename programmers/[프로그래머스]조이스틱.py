from itertools import permutations


def solution(name):
    name_len = len(name)
    answer = 0
    temp_answer = 10000

    check_list = [min(abs(ord('A') - ord(c)), 26 - abs(ord('A') - ord(c))) for c in name]
    answer += sum(check_list)

    move_list = [i for i in range(name_len) if check_list[i] != 0]

    for pick in permutations(move_list, len(move_list)):
        point = 0
        movement = 0
        for num in pick:
            movement += min(abs(point - num), name_len - abs(point - num))
            if movement > temp_answer:
                break
            point = num
        temp_answer = min(temp_answer, movement)

    answer += temp_answer

    return answer