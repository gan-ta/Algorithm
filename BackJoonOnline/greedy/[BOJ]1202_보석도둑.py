import sys
import heapq

input = sys.stdin.readline

if __name__ == '__main__':
    N, K = list(map(int, input().split()))

    jewelry_list = []
    bag_list = []

    for _ in range(N):
        m, v = list(map(int, input().split()))
        jewelry_list.append((m,v))

    for _ in range(K):
        n = int(input())
        bag_list.append(n)

    # 무게가 무거운 순
    jewelry_list.sort(key=lambda x: -x[0])
    # 가방 용량이 가벼운 순
    bag_list.sort()

    ans = 0
    heap = []

    # 현재 가방 용량 중에서 가장 무거운 것을 담을 수 있는 것 고르기
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

