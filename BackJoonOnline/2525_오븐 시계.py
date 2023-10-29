if __name__ == '__main__':
    A, B = list(map(int, input().split()))
    C = int(input())

    M = B + C

    if M < 60:
        print(f"{A} {M}")
    else:
        temp = int(M / 60)
        M -= (60 * temp)
        H = A + temp
        temp2 = int(H / 24)
        H -= (24 * temp2)
        print(f"{H} {M}")
