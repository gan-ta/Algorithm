def ten_to_n(ten, n):
    ret = ''

    change_dict = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4',
                   5: '5', 6: '6', 7: '7', 8: '8', 9: '9',
                   10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}
    if ten == 0:
        ret += '0'
    while ten >= 1:
        remain = ten % n
        ten //= n
        ret = change_dict[remain] + ret

    return ret


def solution(n, t, m, p):
    answer = ''
    total_str = ''
    check_num = 0
    p -= 1

    while len(total_str) < t * m:
        total_str += ten_to_n(check_num, n)
        check_num += 1

    while len(answer) < t:
        answer += total_str[p]
        p += m

    return answer