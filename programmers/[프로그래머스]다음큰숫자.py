def to_binary(num_):
    ret = ''
    while num_ > 0:
        remain = num_ % 2
        ret = str(remain) + ret
        num_ //= 2

    return ret


def to_num(bin_):
    ret = 0
    count = 0
    while len(bin_) != 0:
        if bin_[-1] == '1':
            ret += pow(2, count)
        count += 1
        bin_ = bin_[:len(bin_) - 1]

    return ret


def solution(n):
    check_num = n + 1

    n_binary = to_binary(n)
    one_amount = n_binary.count('1')

    while True:
        search = to_binary(check_num)
        if search.count('1') == one_amount:
            break
        check_num += 1

    return to_num(search)