if __name__ == '__main__':
    n = int(input())

    check = int(n / 4)

    res = ""

    for i in range(0, check):
        res += "long "

    res += "int"

    print(res)