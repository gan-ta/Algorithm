import math
from itertools import permutations


def is_prime(n):
    search_len = int(math.sqrt(n))

    if n == 0 or n == 1:
        return False

    for i in range(2, search_len+1):
        if n % i == 0:
            return False
    return True


def solution(numbers):
    answer = []

    number_len = len(numbers)
    number_list = list(numbers)

    for i in range(1, number_len+1):
        search_list = permutations(number_list, i)
        for num in set(search_list):
            search_num = ''.join(num)
            if is_prime(int(search_num)):
                answer.append(int(search_num))

    return len(set(answer))


if __name__ == '__main__':
    print(solution("011"))
