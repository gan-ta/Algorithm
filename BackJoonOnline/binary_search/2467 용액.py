if __name__ == "__main__":
    N = int(input())
    solutions = list(map(int, input().split(" ")))

    solutions.sort()

    low = 0
    high = len(solutions) - 1

    res = []
    res_num = 0

    while True:
        if low >= high:
            break

        mix = solutions[high] + solutions[low]
        temp = abs(mix)

        if len(res) == 0:
            res = [str(solutions[low]), str(solutions[high])]
            res_num = temp
        else:
            if temp <= res_num:
                res = [str(solutions[low]), str(solutions[high])]
                res_num = temp

        if mix <= 0:
            low += 1
        else:
            high -= 1

    print(" ".join(res))

