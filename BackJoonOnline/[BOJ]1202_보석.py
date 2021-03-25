import heapq
from sys import stdin

input = stdin.readline

if __name__ == '__main__':
    N, K = list(map(int, input().split()))

    jewelry_list = []
    bag_list = []
    heap = []

    for _ in range(N):
        M, V = list(map(int, input().split()))
        jewelry_list.append((M, V))

    for _ in range(K):
        C = int(input())
        bag_list.append(C)

    jewelry_list.sort(key=lambda x: -x[0])
    bag_list.sort()

    ans = 0

    heap = []

    for bag in bag_list:
        while len(jewelry_list) != 0:
            search = jewelry_list.pop()
            if search[0] > bag:
                jewelry_list.append(search)
                break
            else:
                heapq.heappush(heap, (-search[1], search[1]))

        if len(heap) != 0:
            search = heapq.heappop(heap)
            ans += search[1]

    print(ans)
