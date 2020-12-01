def calc(n):
    return input_str.count(chr(n + 97)) + input_str.count(chr(n + 65))


if __name__ == '__main__':
    input_str = input()

    check = [0] * 26

    max_value = -1
    max_idx = -1

    for i in range(0, 26):
        check[i] = calc(i)
        if max_value < check[i]:
            max_value = check[i]
            max_idx = i

    if check.count(check[max_idx]) > 1:
        print('?')
    else:
        print(chr(max_idx + 65))

