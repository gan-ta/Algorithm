
if __name__ == "__main__":
    N, C = list(map(int, input().split(" ")))
    home = []
    res = 0

    for _ in range(N):
        home.append(int(input()))

    home = sorted(home)

    low = 1
    high = max(home)

    while True:
        if low > high:
            break

        mid = (low + high) // 2

        temp = home[0]
        cnt = 1

        for h in home[1:]:
            if h - temp >= mid:
                cnt += 1
                temp = h

        if cnt >= C:
            res = max(res, mid)
            low = mid + 1
        else:
            high = mid - 1

    print(res)