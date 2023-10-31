if __name__ == "__main__":
    items = list(map(int, input().split()))

    res = [0 for _ in range(len(items))]

    for i in range(len(items)):
        if i == 0:
            res[i] = 1 - items[i]
        elif i == 1:
            res[i] = 1 - items[i]
        elif i == 2:
            res[i] = 2 - items[i]
        elif i == 3:
            res[i] = 2 - items[i]
        elif i == 4:
            res[i] = 2 - items[i]
        elif i == 5:
            res[i] = 8 - items[i]

    ans = ""
    for r in res:
        ans += str(r) + " "

    print(ans)