if __name__ == "__main__":
    N, M = list(map(int, input().split()))

    A = []
    B = []

    for _ in range(N):
        temp = list(map(int, input().split()))
        A.append(temp)
    for _ in range(N):
        temp = list(map(int, input().split()))
        B.append(temp)

    for i in range(N):
        for j in range(M):
            A[i][j] += B[i][j]

    for i in range(N):
        res = ""
        for j in range(M):
            res += str(A[i][j]) + " "
        print(res.strip())