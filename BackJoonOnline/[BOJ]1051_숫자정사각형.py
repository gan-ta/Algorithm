if __name__ == '__main__':
    N, M = input().split()
    N = int(N)
    M = int(M)
    max_len = max(N,M)

    graph = list()
    check = 0
    answer = 0

    for _ in range(N):
        graph.append(input())

    for distance in range(max_len-1, -1, -1):
        for r in range(N):
            rp = r + distance
            if rp >= N:
                continue

            for c in range(M):
                cp = c + distance

                if cp >= M:
                    continue

                if graph[r][c] == graph[r][cp] and graph[r][c] == graph[rp][c] and graph[r][c] == graph[rp][cp]:
                    answer = pow(distance+1, 2)
                    check = 1
                if check == 1:
                    break
        if check == 1:
            break
    print(answer)
