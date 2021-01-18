from functools import reduce
import heapq


def solution(n, works):
    answer = 0
    new_works = [[-work, work] for work in works]
    heapq.heapify(new_works)

    for i in range(n):
        search = heapq.heappop(new_works)
        if search[0] == 0:
            break
        heapq.heappush(new_works, [search[0] + 1, search[1] - 1])

    return reduce(lambda acc, cur: acc + pow(cur[1], 2), new_works, 0)