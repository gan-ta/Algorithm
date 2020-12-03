if __name__ == '__main__':
    n, k = input().split()
    n = int(n)
    k = int(k)

    str_list = list()
    standard_list = list()

    check = 0

    str_len = int(input())
    temp = input()
    standard_list = temp.split()

    for i in range(1, n):
        str_len = int(input())
        temp = input()
        str_list.append(temp)

    for i in range(0, len(standard_list) - k + 1):
        search_str = ''
        reverse_str = ''
        for j in range(0, k):
            search_str += standard_list[i+j] + ' '
            reverse_str += standard_list[i + (k-1-j)] + ' '

        search_str = search_str[:len(search_str) - 1]
        reverse_str = reverse_str[:len(reverse_str) -1]

        #포함관계 조사
        check = 0
        for j in range(0, len(str_list)):
            if str_list[j].find(search_str) == -1 and str_list[j].find(reverse_str) == -1:
                check = 1
                break

        if check == 0:
            break

    if check == 0:
        print('YES')
    else:
        print('NO')