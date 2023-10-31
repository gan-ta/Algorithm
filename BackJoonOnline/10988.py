if __name__ == "__main__":
    s = input()
    flag = True

    temp = int(len(s) / 2)
    for i in range(temp):
        if s[i] != s[(len(s) - 1) - i]:
            flag = False

    if not flag:
        print("0")
    else:
        print("1")
