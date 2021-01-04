from itertools import combinations


def is_prime(n):
    search_len = int(n ** 0.5)

    if n == 0 or n == 1:
        return False

    for i in range(2, search_len + 1):
        if n % i == 0:
            return False

    return True


def solution(nums):
    answer = 0

    for pick_list in combinations(nums, 3):
        search_num = sum(pick_list)
        if is_prime(search_num):
            answer += 1

    return answer