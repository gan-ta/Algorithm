if __name__ == '__main__':
    N , M = list(map(int, input().split()))

    arr = list(map(int, input().split()))

    dp = [0] * (N+1)

    check_list = []

    for _ in range(M):
        check_list.append(list(map(int, input().split())))

    dp[1] = arr[0]
    for i in range(2, N+1):
        dp[i] = dp[i-1] + arr[i-1]

    for check in check_list:
        print(dp[check[1]] - dp[check[0] - 1])