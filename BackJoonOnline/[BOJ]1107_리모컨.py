if __name__ == "__main__":
    aim = int(input())
    N = int(input())
    if N != 0:
        error_num_list = list(input().split())
    else:
        error_num_list = list()

    answer = abs(100 - aim)

    for i in range(1000001):
        check = True
        for search in str(i):
            if search in error_num_list:
                check = False
                break
        if check:
            answer = min(answer, abs(aim - i) + len(str(i)))

    print(int(answer))
