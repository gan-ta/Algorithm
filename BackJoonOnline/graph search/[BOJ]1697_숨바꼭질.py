from collections import deque

if __name__ == '__main__':

    N, K = map(int, input().split())
    visited = [0] * 200005

    dq = deque()

    visited[N] = 1
    dq.appendleft([N, 0])

    ans = 987654321

    while len(dq) != 0:
        search = dq.pop()

        if search[0] == K:
            print(search[1])
            break

        n1 = search[0] + 1
        n2 = search[0] - 1
        n3 = search[0] * 2


        if 0 <= n1 and n1 <= 100000 and visited[n1] == 0:
            visited[n1] = 1
            dq.appendleft([n1, search[1] + 1])

        if 0 <= n2  and n2 <= 100000 and visited[n2] == 0:
            visited[n2] = 1
            dq.appendleft([n2, search[1] + 1])

        if 0 <= n3 and n3 <= 100000 and visited[n3] == 0:
            visited[n3] = 1
            dq.appendleft([n3, search[1] + 1])
