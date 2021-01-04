import heapq


def solution(scoville, K):
    answer = 0
    heap = []

    for num in scoville:
        heapq.heappush(heap, num)

    while heap[0] < K:
        if len(heap) > 1:
            a = heapq.heappop(heap)
            b = heapq.heappop(heap)
            insert = a + (b * 2)
            heapq.heappush(heap, insert)
        else:
            return -1
        answer += 1

    return answer
