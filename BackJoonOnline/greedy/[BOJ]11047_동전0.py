if __name__ == '__main__':
    N, K = list(map(int, input().split()))
    coin_list = []
    res = 0

    for _ in range(N):
        coin_list.append(int(input()))

    coin_list.sort(reverse=True)

    for coin in coin_list:
        res += K // coin
        K = K % coin

    print(res)