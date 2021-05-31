import sys
import heapq
input = sys.stdin.readline

if __name__ == '__main__':
    N = int(input())
    class_list = []
    heap = []

    for _ in range(N):
        s, t = map(int, input().split())
        class_list.append([s,t])

    # 강의의 시작 순으로 정렬
    class_list = sorted(class_list, key = lambda x : x[0])

    heapq.heappush(heap,class_list[0][1])

    # 순회하며 끝나는 시각을 heapq에 저장
    for info in class_list[1:]:
        s, t = info
        check = heap[0]

        # 만약 강의가 끝나는 시각이 아니라면
        if check > s:
            heapq.heappush(heap, t)
        else:
            heapq.heappop(heap)
            heapq.heappush(heap, t)

    print(len(heap))
