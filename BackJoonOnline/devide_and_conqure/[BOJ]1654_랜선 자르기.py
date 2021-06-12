def check_split(line_list, mid, aim):
    res = 0

    for line in line_list:
        res += (line // mid)

    if res >= aim:
        return True
    elif res < aim:
        return False

if __name__ == '__main__':
    K, N = list(map(int, input().split()))

    line_list = []

    for _ in range(K):
        insert = int(input())
        line_list.append(insert)

    low = 1
    high = pow(2,31)

    max_num = 0

    while low <= high:
        mid = (low + high) // 2

        check = check_split(line_list, mid, N)

        if check:
            max_num = max(max_num, mid)
            low = mid + 1
        else:
            high = mid - 1

    print(max_num)
