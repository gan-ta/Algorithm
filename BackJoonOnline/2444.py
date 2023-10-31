if __name__ == "__main__":
    T = int(input())

    temp = []

    for i in range(T):
        res = ""
        for _ in range((T - 1) - i):
            res += " "
        for _ in range(i):
            res += "*"
        res += "*"
        for _ in range(i):
            res += "*"
        temp.append(res)

    for t in temp:
        print(t)
    res_temp = temp[:-1]
    for rt in res_temp[::-1]:
        print(rt)