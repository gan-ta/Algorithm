if __name__ == "__main__":
    N = int(input())
    res = []
    side_len = 2

    for i in range(16):
        if i == 0:
            res.append(4)
            continue
        total = (res[-1] * 4) - (side_len * 4) + 1
        side_len = (side_len * 2 - 1)
        res.append(total)
    print(res[N])

