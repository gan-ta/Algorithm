if __name__ == "__main__":
    s = input()

    dictionary = ("c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=")

    flag = True

    res = 0
    idx = 0

    while True:
        if idx >= len(s):
            break

        if s[idx: idx + 2] in dictionary:
            res += 1
            idx += 2
            continue
        if s[idx: idx + 3] in dictionary:
            res += 1
            idx += 3
            continue

        res += 1
        idx += 1

    print(res)

