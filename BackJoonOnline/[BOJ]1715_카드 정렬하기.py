import heapq

if __name__ == '__main__':
    N = int(input())
    heap = list()
    for i in range(N):
        num = int(input())
        heapq.heappush(heap, num)

    if N == 1:
        print(0)
    else:
        ans = 0
        while len(heap) != 1:
            temp_sum = heapq.heappop(heap) + heapq.heappop(heap)
            ans += temp_sum
            heapq.heappush(heap, temp_sum)
        print(ans)
