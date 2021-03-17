if __name__ == '__main__':
    N = int(input())
    num_list = list(map(int,input().split()))
    ans = -1
    if 1 not in num_list:
        ans = 1
    else:
        num_list.sort()
        temp_sum = num_list[0]
        for i in range(1, len(num_list)):
            n = num_list[i]
            if (temp_sum + 1) < n:
                ans = temp_sum + 1
                break
            temp_sum += n

    if ans == -1:
        print(sum(num_list) + 1)
    else:
        print(ans)
