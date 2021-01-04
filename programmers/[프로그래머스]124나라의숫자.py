def solution(n):
    answer = ''

    num_dict = {0: '4', 1: '1', 2: '2'}

    while n > 0:
        share = n // 3
        remain = n % 3

        if remain == 0:
            share -= 1

        n = share

        answer = num_dict[remain] + answer

    return answer
