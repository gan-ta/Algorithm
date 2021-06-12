if __name__ == '__main__':
    n = int(input())
    arr_list = list(map(int, input().split()))

    m = int(input())
    check_list = list(map(int, input().split()))

    arr_list.sort()

    for i in range(m):
        l = 0
        r = n - 1
        aim = check_list[i]
        flag = False

        while l <= r:
            mid = (l + r) // 2

            if arr_list[mid] == aim:
                flag = True
                break
            elif arr_list[mid] < aim:
                l = mid + 1
            else:
                r = mid - 1
        if flag:
            print(1)
        else:
            print(0)
