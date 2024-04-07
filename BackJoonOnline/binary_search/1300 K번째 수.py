if __name__ == "__main__":
    n = int(input())
    k = int(input())

    low = 1
    high = n * n

    res = -1

    while True:
        if low > high:
            break

        mid = (low + high) // 2
        cnt = 0

        for i in range(1, n + 1):
            cnt += min(mid // i, n)

        if cnt >= k:
            res = mid
            high = mid - 1
        else:
            low = mid + 1
    print(res)