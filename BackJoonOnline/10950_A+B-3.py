if __name__ == '__main__':
    N = int(input())

    for i in range(0, N):
        A, B = list(map(int, input().split()))
        print(A + B)