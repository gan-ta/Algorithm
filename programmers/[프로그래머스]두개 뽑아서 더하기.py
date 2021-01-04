from itertools import combinations


def solution(numbers):
    answer = set()

    for pick in combinations(numbers, 2):
        answer.add(pick[0] + pick[1])

    return sorted(list(answer))