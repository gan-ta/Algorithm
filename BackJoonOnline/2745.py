if __name__ == "__main__":
    n, b = input().split()

    b = int(b)

    res = 0
    n_list = list(n)
    n_list.reverse()
    for idx, num in enumerate(n_list):
        if num.isdigit():
            res += (int(b) ** idx) * int(num)
        else:
            res += (int(b) ** idx) * (ord(num) - ord("A") + 10)
    print(res)

