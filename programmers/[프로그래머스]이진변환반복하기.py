def calc(s_):
    zero_count = 0
    one_count = 0

    for c in s_:
        if c == '0':
            zero_count += 1
        else:
            one_count += 1

    return [zero_count, bin(one_count)[2:]]


def solution(s):
    total_zero = 0
    count = 0

    while s != '1':
        result = calc(s)
        total_zero += result[0]
        s = result[1]
        count += 1

    return [count, total_zero]
