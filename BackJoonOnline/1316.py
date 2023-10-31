if __name__ == "__main__":
    N = int(input())
    res = 0
    for _ in range(N):
        alpha = set()
        temp = input()
        flag = True

        for idx in range(len(temp)):
            if idx == 0:
                alpha.add(temp[idx])
                continue

            if temp[idx] != temp[idx - 1] and temp[idx] in alpha:
                flag = False
                break

            alpha.add(temp[idx])

        if flag:
            res += 1

    print(res)

