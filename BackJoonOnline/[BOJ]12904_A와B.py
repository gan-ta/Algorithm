if __name__ == '__main__':
    S = input()
    T = input()
    s_len = len(S)

    while s_len != len(T):
        if T[-1] == 'A':
            T = T[:-1]
        else:
            T = T[:-1]
            T = T[::-1]

    if T == S:
        print(1)
    else:
        print(0)