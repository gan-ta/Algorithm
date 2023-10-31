if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        num, temp = input().split()
        num = int(num)

        res = ""

        for c in temp:
            for _ in range(num):
                res += c

        print(res)