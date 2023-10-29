if __name__ == '__main__':
    M, H = map(int, input().split())

    temp_H = H - 45

    if temp_H >= 0:
        print(f"{M} {temp_H}")
    else:
        if M - 1 < 0:
            print(f"{23} {60 + temp_H}")
        else:
            print(f"{M-1} {60 + temp_H}")