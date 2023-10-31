if __name__ == "__main__":
    res = [-1 for _ in range(ord("a"), ord("z") + 1)]
    temp = input()

    for index, c in enumerate(temp):
        idx = ord(c) - ord("a")
        if res[idx] == -1:
            res[idx] = index

    answer = ""
    for r in res:
        answer += str(r) + " "

    print(answer)