from functools import reduce


def solution(clothes):
    cloth_dict = {}

    for pick in clothes:
        if pick[1] in cloth_dict.keys():
            cloth_dict[pick[1]].append(pick[0])
        else:
            cloth_dict[pick[1]] = [pick[0]]

    answer = reduce(lambda acc, cur: acc * (len(cur)+1), cloth_dict.values(), 1)

    return answer - 1

